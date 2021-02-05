CC = gcc

CFLAGS = -Wall -O

DEPS	= uab_sh.h Makefile
EXECS	= uab_sh fibonacci hello

all:	$(EXECS)

%.o:	%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

uab_sh: uab_sh.o
	$(CC) $(CFLAGS) -o $@ $^

fibonacci: fibonacci.o
	$(CC) $(CFLAGS) -o $@ $^

hello:  hello.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	/bin/rm -i *.o $(EXECS) 
