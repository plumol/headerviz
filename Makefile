CC = g++
FLAGS = -Wall -Werror

build-cli: 
	$(CC) $(FLAGS) $^ -o $@

.PHONY: all clean format
