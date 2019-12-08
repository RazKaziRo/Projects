CC=gcc -ansi -pedantic-errors -Wall -Wextra -g
TARGET=output

output: bits_arr_test.o bits_array.o 
	$(CC) bits_arr_test.o bits_array.o -o $(TARGET)

bits_arr_test.o: bits_arr_test.c
	$(CC) -c bits_arr_test.c

bits_array.o: bits_array.c bits_array.h
	$(CC) -c bits_array.c

clean:
	rm *.o