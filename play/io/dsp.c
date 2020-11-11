#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <linux/soundcard.h>
#include <stdint.h>
#include <string.h>

// Example of using regular file i/o to talk
// to something that is not a file at all

//
// This assumes your kernel support /dev/dsp
// as the generic sound card port (e.g., OSS)
//
// Try cat /dev/urandom > /dev/dsp to see if you have this
//


// Set Device Parameter with error checking
// ioctl is the "out of band" access to the 
// "file"
#define ioset(field, argument)\
{\
    int arg = argument;\
    if(ioctl(fd, field, &arg)<0)\
        perror(#field "ioctl failed");\
    else if(arg!=argument)\
        perror(#argument "was not set in ioctl");\
    else\
        printf(#argument "\t:= %d\n", arg);\
}

int write_all(int fd, uint8_t *buf, int count)
{
   int left = count ;

   while (left) { 
       int rc = write(fd,buf+count-left,left);
       if (rc<0) { 
            perror("failed to write");
            exit(-1);
       } else if (rc==0) { 
            printf("End of stream - huh?\n");
            exit(-1);
       } else {
            left -= rc;
       }
   }
   return 0;
} 

int main(int argc, char *argv[])
{
    if (argc!=2) { 
        printf("dsp Hz\n");
        return -1;
    }

    int HZ = atoi(argv[1]);

    // Device Parameters
    int SampleRate = 48000; 
    int Channels   = 1;     //mono
    int SampleBits = 8;

    // Note that the open of the device is the same
    // as an open of a file
    int fd = open("/dev/dsp", O_WRONLY);
    if(fd < 0) {
        perror("open of /dev/dsp failed");
        return 1;
    }

    // Configure Sound Device
    // this uses ioctl, which is the way to 
    // access aspects of the "file" that are
    // not part of the "stream of bytes" model
    // This configures it to 48 KHz, 1 channel, 8 bits per channel
    ioset(SOUND_PCM_WRITE_BITS,     SampleBits);
    ioset(SOUND_PCM_WRITE_CHANNELS, Channels);
    ioset(SOUND_PCM_WRITE_RATE,     SampleRate);

    // Sound Buffer
    // We will build 1 second of audio
    uint8_t buf[SampleRate];
    const unsigned BlockSize = SampleRate/HZ/2;

    const unsigned Blocks    = SampleRate/BlockSize;

    char state = 0;
    while(1) {
        unsigned i;
        for(i=0; i<Blocks; ++i) {
            state = !state;
            // 0x7f => maximum volume (2s complememt)
            memset(buf+i*BlockSize, state ? 0x7f : 0x00, BlockSize);
        }

        //Send to Soundcard
        write_all(fd,buf,sizeof(buf));
    }
}

