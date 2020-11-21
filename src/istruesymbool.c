#include "header.h"

bool istrue_symbol(char *str)
{
	while (*str)
	{
		if (*str != '#' || *str != ',' || *str != '.' || *str != '\n')
		{
			return true;
		}

		printf("char - %c -\n", *str);
		str++;
	}
	return false;
}
