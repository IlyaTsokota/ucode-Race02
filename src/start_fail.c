#include "header.h"

void start_fail(int count_args, const char *filename)
{
	if (count_args != 6)
	{
		mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
		exit(0);
	}
	isempty_or_missing_file(filename);
	ismap_error(filename);
}
