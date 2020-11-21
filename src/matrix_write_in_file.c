#include "header.h"
void matrix_write_in_file(char **final_matrix, int file, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			char s = final_matrix[i][j];

			write(file, &s, 1);
		}

		write(file, "\n", 1);
	}
	close(file);
}
