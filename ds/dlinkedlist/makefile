CC= gcc 
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
TARGET= output

output: dlinkedlist.o dlinkedlist_test.o
	@$(CC) $(CFLAGS) dlinkedlist.o dlinkedlist_test.o -o $(TARGET)

dlinkedlist_test.o: dlinkedlist_test.c
	@$(CC) $(CFLAGS) -c dlinkedlist_test.c

dlinkedlist.o: dlinkedlist.c dlinkedlist.h
	@$(CC) $(CFLAGS) -c dlinkedlist.c

clean:
	rm *.o
