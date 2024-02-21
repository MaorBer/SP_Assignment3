.PHONY: all clean

CC = gcc
CFLAGS = -Wall -g
TARGET = Main
OBJS = StrList.o Main.o

# The 'all' target builds the specified TARGET
all: $(TARGET)

# Link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile StrList.o from StrList.c
StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c $<

# Compile Main.o from Main.c
Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c $<

# The 'clean' target removes all built files
clean:
	rm -f $(TARGET) $(OBJS)
