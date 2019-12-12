CC= gcc 
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
TARGET= output
DLPATH = ../sortedlist/sortedlist.c
INC = -I../sortedlist/

PROJECT_DIR = .
BUILD_DIR = $(PROJECT_DIR)/obj

all: output

output: sortedlist.o sortedlist_test.o
	@$(CC) $(CFLAGS) sortedlist.o sortedlist_test.o -o $(TARGET)

sortedlist_test.o: sortedlist_test.c 
	@$(CC) $(CFLAGS) -c sortedlist_test.c $(DLPATH) $(INC)

sortedlist.o: sortedlist.c sortedlist.h
	@$(CC) $(CFLAGS) -c sortedlist.c $(DLPATH) $(INC)

clean:
	rm *.o
