CC= gcc 
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
TARGET= output

output: doublelist.o doublelist_test.o
	@$(CC) $(CFLAGS) doublelist.o doublelist_test.o -o $(TARGET)

doublelist_test.o: doublelist_test.c
	@$(CC) $(CFLAGS) -c doublelist_test.c

doublelist.o: doublelist.c doublelist.h
	@$(CC) $(CFLAGS) -c doublelist.c

clean:
	rm *.o
