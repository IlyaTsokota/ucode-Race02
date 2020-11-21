#include "header.h"

static char **filling_arr(int size_row, int size_column, char *res)
{
	char **matrix = (char **)malloc(size_row * 8);

	for (int i = 0; i < size_row; i++)
	{
		matrix[i] = mx_strnew(size_column);
	}

	for (int i = 0; i < size_row; i++)
	{
		for (int j = 0; j < size_column; j++)
		{
			if (i == 0)
			{
				if (res[j] == '#')
				{
					matrix[i][j] = '#';
				}
				else if (res[j] == '.')
				{
					matrix[i][j] = '.';
				}
				else if (res[j] != ',' && res[j] != '\n')
				{
					mx_printerr("map error\n");
					exit(0);
				}
			}
			else
			{
				if (res[j + i * (size_column + 1)] == '#')
				{
					matrix[i][j] = '#';
				}
				else if (res[j + i * (size_column + 1)] == '.')
				{
					matrix[i][j] = '.';
				}
				else if (res[j + i * (size_column + 1)] != ',' && res[j + i * (size_column + 1)] != '\n')
				{
					mx_printerr("map error\n");
					exit(0);
				}
			}
		}
	}
	return matrix;
}

char **create_char_matrix(char *res, int *row, int *column)
{
	int size_column = count_r_or_c(res, count_columns);
	int size_row = count_r_or_c(res, count_rows) + 1;

	*column = size_column;
	*row = size_row;
	return filling_arr(size_row, size_column, res);
}
