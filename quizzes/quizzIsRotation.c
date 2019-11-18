#include <stdio.h>
#include <string.h>

#define green [0;32m


int isRotation(const char *s1, const char *s2)
{
	const char *runner_s1 = s1;
	const char *runner_s2 =  s2;
	int length = strlen(s1);

	if(strlen(s1) != strlen (s2))
	{
		return 0;
	}

	while(length > 0)
	{

		if(0 == strncmp(runner_s1, runner_s2, length))
		{
			runner_s1 = runner_s1 + length;
			runner_s2 = s2;
			length = strlen(s1) - length;
			break;
		}
		else
		{
			++runner_s2;
			--length;
		}
	}

	if(0 == strncmp(runner_s1, runner_s2, length))
	{

		return 1;
	}
	else
	{
		return 0;
	}

}

void Test(int condition, const char *msg)
{
	if (condition)
	{
		printf("SUCCESS \n");
	}
	else
	{
		printf("\033[1;31m");
		printf("%s \n",msg);
		printf("\033[0m");
	}
}

int main()
{


Test(!isRotation("abc","efg") , "FAILED: Not a Rotation ");
Test(isRotation("1234","4123"), "FAILED: A Rotation ");
Test(isRotation("",""), "FAILED: Empty Strings ");
Test(!isRotation("abcd","a"), "FAILED: Different Sizes ");

/*
printf("IsRotation (False): %d \n", isRotation(s3,s4));
*/

return 0;
}
