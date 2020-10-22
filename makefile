CC = g++
CFLAGS = -g -Wall -std=c++17
DEPS = palindrome_prod.h
OBJ = palindrome_prod.o
MAIN = main_palindrome_prod.cc
EXEC = palindrome_prod

all: $(MAIN) $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXEC) $^

%.o: %.cc $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<


#./palindrome_prod.o: palindrome_prod.h palindrome_prod.cc
#	$(CC) $(CFLAGS) -c -o $(OBJ) palindrome_prod.cc


.PHONY: clean

clean:
	 bash -O extglob -c "rm -vf !(*.cc|*.h|"makefile")"
