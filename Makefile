// Makefile
// 20 Dec2018, Simpy Parveen(simpy.parveen1@ucalgary.ca)


BINARY          = runMe
OBJS     		= sha3.o main.o

CC              = gcc
CFLAGS			= -Wall -O3
LIBS            =
LDFLAGS         =
INCLUDES	=

$(BINARY):      $(OBJS)
		$(CC) $(LDFLAGS) -o $(BINARY) $(OBJS) $(LIBS)
