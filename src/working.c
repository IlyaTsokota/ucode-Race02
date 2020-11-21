#include "header.h"

void working(char const *argv[])
{
	int row = 0;
	int column = 0;
	int length = 0;

	char *str = mx_file_to_str(argv[1]);
	int **matrix_for_search_path = create_int_matrix(str, &row, &column);
	int **matrix_for_max_way = create_int_matrix(str, &row, &column);
	char **final_matrix = create_char_matrix(str, &row, &column);

	int x1 = mx_atoi(argv[2]);
	int x2 = mx_atoi(argv[4]);
	int y1 = mx_atoi(argv[3]);
	int y2 = mx_atoi(argv[5]);

	isout_of_range(x1, x2, y1, y2, column, row);

	int px[row * column];
	int py[row * column];

	if (!ispath(matrix_for_search_path, x1, y1, x2, y2, row, column, &length, px, py))
	{
		mx_printerr("route not found\n");
		exit(0);
	}

	int file = open("path.txt", O_WRONLY | O_CREAT);

	for (int i = 0; i < length; i++)
	{
		final_matrix[py[i]][px[i]] = '*';
	}
	final_matrix[y2][x2] = '*';
	max_way(matrix_for_max_way, x1, y1, row, column, final_matrix);

	matrix_write_in_file(final_matrix, file, row, column);

	mx_printstr("dist=");
	mx_printint(max_way(matrix_for_max_way, x1, y1, row, column, final_matrix));
	mx_printstr("\n");
	mx_printstr("exit=");
	mx_printint(length);
	mx_printstr("\n");
}
