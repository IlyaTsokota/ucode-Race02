#include "header.h"

void ismap_error(const char *filename)
{
	char *str_from_file = mx_file_to_str_second(filename);
	if (!istrue_symbol(str_from_file))
	{
		mx_printerr("map error\n");
		exit(0);
	}
	char *str_clear_string = clear_string(str_from_file);
	int columns_count = count_r_or_c(str_clear_string, count_columns);
	int rows_count = count_r_or_c(str_clear_string, count_rows);
	if (isrectangular(str_clear_string, rows_count, columns_count))
	{
		mx_printerr("map error\n");
		exit(0);
	}
}
