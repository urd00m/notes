all: divzero badaddr badaddr-signal sleepy-signal forkwait forkbomb shell

forkwait: forkwait.c
	gcc -m64 -g forkwait.c -o forkwait

forkbomb: forkbomb.c
	gcc -m64 -g forkbomb.c -o forkbomb

shell: shell.c
	gcc -m64 -g shell.c -o shell

divzero: divzero.c
	gcc -m64 -g divzero.c -o divzero

badaddr: badaddr.c
	gcc -m64 -g badaddr.c -o badaddr

badaddr-signal: badaddr-signal.c
	gcc -m64 -g badaddr-signal.c -o badaddr-signal

sleepy-signal: sleepy-signal.c
	gcc -m64 -g sleepy-signal.c -o sleepy-signal

clean:
	rm divzero badaddr badaddr-signal sleepy-signal forkwait shell forkbomb

