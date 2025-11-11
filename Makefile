# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRC = $(wildcard src/*.c)

# Object files (replace .c with .o)
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = dpms

# Default target: build everything
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Compile each .c file into .o
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
