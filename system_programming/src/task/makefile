CC= gcc 
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
TARGET= output

output: cbuffer.o cbuffer_test.o
	@$(CC) $(CFLAGS) cbuffer.o cbuffer_test.o -o $(TARGET)

cbuffer_test.o: cbuffer_test.c
	@$(CC) $(CFLAGS) -c cbuffer_test.c

cbuffer.o: cbuffer.c cbuffer.h
	@$(CC) $(CFLAGS) -c cbuffer.c

clean:
	rm *.o
