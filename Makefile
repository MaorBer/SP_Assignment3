CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

TARGET = Main
OBJS = StrList.o Main.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c StrList.h
    $(CC) $(CFLAGS) -c $<

clean:
    $(RM) $(TARGET) $(OBJS)
