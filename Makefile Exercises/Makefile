SRC = print_hello.c \
	  main.c
OBJ = print_hello.o \
	  main.o
CC = gcc
FLAGS = -Wall -Wextra -Werror
OUTPUT = hello

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(OUTPUT)

%.o:	%.c
	$(CC) $(FLAGS) $< -c $@

clean:
	rm -f $(OBJ)

cleanf:
	rm -f $(OBJ) $(OUTPUT)

.PHONY:	clean cleanf all