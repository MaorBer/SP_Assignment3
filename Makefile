.PHONY: all clean

CC = gcc
CFLAGS = -Wall -g
TARGET = Main
OBJS = StrList.o Main.o

all: $(TARGET)

Main: $(OBJS)
	$(CC) $(CFLAGS) -o Main $(OBJS)

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

clean:
	rm -f Main $(OBJS)
