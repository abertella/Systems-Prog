CC = gcc

CFLAGS = -Wall -O

DEPS	= Makefile
OBJS	= berba_hw2.o
EXECS	= berba_hw2

all:	$(EXECS)

%.o:	%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

berba_hw2: $(OBJS) berba_hw2.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	/bin/rm -i *.o $(EXECS) 
