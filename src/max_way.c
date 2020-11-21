#include "header.h"

int max_way(int **grid, int x1, int y1, int count_row, int count_column, char **final)
{
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int d = 0;
	int x = 0;
	int y = 0;
	int k = 0;
	bool stop = false;
	int maxim = 0;
	int flag = 1;
	grid[y1][x1] = 0;

	while (!stop || flag)
	{
		stop = true;

		for (y = 0; y < count_row; y++)
		{
			for (x = 0; x < count_column; x++)
			{
				if (grid[y][x] == d)
				{
					for (k = 0; k < 4; k++)
					{
						int iy = y + dy[k];
						int ix = x + dx[k];

						if (iy >= 0 && iy < count_row && ix >= 0 && ix < count_column && grid[iy][ix] == -2)
						{
							stop = false;
							grid[iy][ix] = d + 1;
						}
					}
				}
			}
		}
		d++;
		flag = 0;
	}

	maxim = grid[0][0];

	for (int i = 0; i < count_row; i++)
	{
		for (int j = 0; j < count_column; j++)
		{
			if (grid[i][j] > maxim)
				maxim = grid[i][j];
		}
	}

	for (int i = 0; i < count_row; i++)
	{
		for (int j = 0; j < count_column; j++)
		{
			if (grid[i][j] == maxim)
			{
				if (final[i][j] == '*')
				{
					final[i][j] = 'X';
				}
				else
				{
					final[i][j] = 'D';
				}
			}
		}
	}

	return maxim;
}
