# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Sources and objects
SRC = src/intArrayLib.c src/charArrayLib.c examples/main.c
OBJ = $(SRC:.c=.o)

# Target program
TARGET = program

# Build executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Dependencies
src/intArray.o: src/intArrayLib.c include/intArrayLib.h
src/charArray.o: src/charArrayLib.c include/charArrayLib.h
examples/main.o: examples/main.c include/intArrayLib.h include/charArrayLib.h

# Clean build files
clean:
	rm -f src/*.o examples/*.o $(TARGET)
