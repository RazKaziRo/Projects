CC= gcc 
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
TARGET= output

output: circularbuffer.o circularbuffer_test.o
	@$(CC) $(CFLAGS) circularbuffer.o circularbuffer_test.o -o $(TARGET)

circularbuffer_test.o: circularbuffer_test.c
	@$(CC) $(CFLAGS) -c circularbuffer_test.c

circularbuffer.o: circularbuffer.c circularbuffer.h
	@$(CC) $(CFLAGS) -c circularbuffer.c

clean:
	rm *.o
