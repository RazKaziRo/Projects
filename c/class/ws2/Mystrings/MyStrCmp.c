 #include <stdio.h>

 int MyStrCmp(const char *s1, const char *s2)
 {

 	char const *runner1 = s1, *runner2 = s2;
 	
 	while (*runner1 == *runner2)
 	{
		++runner1;
	 	++runner2;
 	}
 return *runner1-*runner2;
 }
