#include <stdio.h>

int flips (int n)
{

	int newnum = 0, leftover;

	while (n != 0) 
	{
	leftover = n % 10;
	newnum = newnum * 10 + leftover;
	n = n / 10;
	}

return newnum;

}
