#include "header.h"

void isempty_or_missing_file(const char *filename)
{

	int file = open(filename, O_RDONLY);
	if (file < 0)
	{
		mx_printerr("map does not exist\n");
		exit(0);
	}

	char sym[1];
	int size = read(file, sym, 4);
	if (size <= 0)
	{
		mx_printerr("map does not exist\n");
		exit(0);
	}
	close(file);
}
