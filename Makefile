OBJS = Menu.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o Menu

clean:
	\rm *.o *~ Menu *.exe *.exe.stackdump

tar:
	tar cfv GenericMenu.tar GenericOOPMenu.hpp Menu.c Makefile
