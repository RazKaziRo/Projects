CC=gcc -ansi -pedantic-errors -Wall -Wextra -g
TARGET=output

output: vector.o vector_test.o
	$(CC) vector.o vector_test.o -o $(TARGET)

vector_test.o: vector_test.c
	$(CC) -c vector_test.c

vector.o: vector.c vector.h
	$(CC) -c vector.c

clean:
	rm *.o
