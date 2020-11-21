#include "header.h"

int count_rows(char *str)
{
	int count = 0;
	while (*str)
	{
		if (*str == '\n')
			count++;
		str++;
	}
	return count;
}

int count_columns(char *str)
{
	int count = 0;
	while (*str)
	{
		if (*str == '\n')
			break;
		count++;
		str++;
	}
	return count;
}

int count_r_or_c(char *str, int (*f)(char *))
{
	return f(str);
}
