#include <stdint.h>
#include <stdio.h>

void signed_overflow(int x, int ymin, int ymax)
{
  // designed for 8 bits only
  int8_t x8 = (int8_t) x;
  int8_t y8;
  int8_t ymin8 = (int8_t) ymin;
  int8_t ymax8 = (int8_t) ymax;
  
  for (y8 = ymin8; (y8 <= ymax8) && (ymin<=ymax) ; y8++, ymin++) { 
    printf("%hhd\t%hhd\t%hhd\n", x8, y8, x8+y8);
  }
}
    
void unsigned_overflow(int x, int ymin, int ymax)
{
  // designed for 8 bits only
  uint8_t x8 = (int8_t) x;
  uint8_t y8;
  uint8_t ymin8 = (int8_t) ymin;
  uint8_t ymax8 = (int8_t) ymax;

  for (y8 = ymin8; (y8 <= ymax8) && (ymin<=ymax); y8++, ymin++) { 
    printf("%hhu\t%hhu\t%hhu\n", x8, y8, x8+y8);
  }
}

int main(int argc, char *argv[])
{
  int x, ymin, ymax;

  if (argc!=5) { 
    printf("usage: overflow signed|usigned xconst ymin ymax\n");
    return -1;
  }
  
  x = atoi(argv[2]);
  ymin = atoi(argv[3]);
  ymax = atoi(argv[4]);

  if (argv[1][0]=='s') { 
    signed_overflow(x,ymin,ymax);
  } else {
    unsigned_overflow(x,ymin,ymax);
  }
}


