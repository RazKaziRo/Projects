CC=gcc -ansi -pedantic-errors -Wall -Wextra -g
TARGET=output

output: sll.o sll_test.o
	$(CC) sll.o sll_test.o -o $(TARGET)

sll_test.o: sll_test.c
	$(CC) -c sll_test.c

sll.o: sll.c sll.h
	$(CC) -c sll.c

clean:
	rm *.o
