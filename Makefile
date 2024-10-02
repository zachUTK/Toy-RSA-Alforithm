#Compiler
CC = gcc

#Flags
FLAGS = -Wall -g -lgmp

#The executable
TARGET = RSA

#Source files
SRCS = RSA.c RSA_helper.c

#Object files
OBJS = $(SRCS:.c=.o)

#Build the target executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(FLAGS)

#Compile source files into object files
%.o: %.c RSA_helper.h
	$(CC) $(FLAGS) -c $<

#Clean generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
