#include "header.h"

char *clear_string(char *str)
{
	int count = 0;
	char *s1 = str;
	while (*s1)
	{
		if (*s1 != ',')
			++count;
		++s1;
	}
	char *s = mx_strnew(count);
	char *s2 = s;
	s1 = str;
	while (*s1)
	{
		if (*s1 != ',')
		{
			*s = *s1;
			++s;
		}
		++s1;
	}
	return s2;
}
