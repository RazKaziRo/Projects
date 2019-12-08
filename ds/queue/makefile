CC=gcc -ansi -pedantic-errors -Wall -Wextra -g -I
TARGET=output
SLL_PATH = ../slinkedlist/

output: queue.o queue_test.o
	$(CC)$(SLL_PATH) queue.o queue_test.o -o $(TARGET)

queue_test.o: queue_test.c
	$(CC)$(SLL_PATH) -c queue_test.c 

queue.o: queue.c queue.h
	$(CC)$(SLL_PATH) -c queue.c $(SLL_PATH)slinkedlist.c

clean:
	rm *.o
