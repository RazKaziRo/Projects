 #include <stdio.h>

 int MyStrcmp(const char *s1, const char *s2)
 {

 	char const *runner1 = s1, *runner2 = s2;
 	int tmpsts = 0;

 	while ('\0'!=*runner1 || '\0'!=*runner2 )
 	{
	 		if(*runner1 > *runner2)
	 		{
	 			tmpsts = *runner1 - *runner2;
	 			++runner1;
	 			++runner2;
	 		}
	 		else
	 		{
	 			tmpsts = *runner1 - *runner2;
	 			++runner1;
	 			++runner2;
	 		}
 	}
 return tmpsts;
 }