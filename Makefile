.PHONY: all clean

CC = gcc
CFLAGS = -Wall -g
TARGET = StrList
OBJS = StrList.o Main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

clean:
	rm -f $(TARGET) $(OBJS)
