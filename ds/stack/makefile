CC=gcc -ansi -pedantic-errors -Wall -Wextra -g
TARGET=output

output: stack.o stack_test.o
	$(CC) stack.o stack_test.o -o $(TARGET)

stack_test.o: stack_test.c
	$(CC) -c stack_test.c

stack.o: stack.c stack.h
	$(CC) -c stack.c

clean:
	rm *.o
