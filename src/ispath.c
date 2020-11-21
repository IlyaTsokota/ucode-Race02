#include "header.h"

static void fail(int var)
{
	if (var == -1)
	{
		mx_printerr("entry point cannot be an obstacle\n");
		exit(0);
	}
}

bool ispath(int **grid, int x1, int y1, int x2, int y2, int row, int column, int *length, int *pathX, int *pathY)
{
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	//loop
	int i = 0;
	int j = 0;
	int l = 0;
	int k = 0;
	bool stop = false;
	fail(grid[y1][x1]);
	fail(grid[y2][x2]);
	grid[y1][x1] = 0;

	while (true)
	{
		stop = true;
		for (l = 0; l < row; l++)
			for (j = 0; j < column; j++)
				if (grid[l][j] == i)
				{
					for (k = 0; k < 4; k++)
					{
						int iy = l + dy[k];
						int ix = j + dx[k];
						if (iy >= 0 && iy < row && ix >= 0 && ix < column && grid[iy][ix] == -2)
						{
							stop = false;
							grid[iy][ix] = i + 1;
						}
					}
				}
		i++;

		if ((stop || grid[y2][x2] != -2))
			break;
	}

	if (grid[y2][x2] == -2)
		return false;

	*length = grid[y2][x2];
	j = x2;
	l = y2;
	i = *length;

	while (i > 0)
	{
		pathX[i] = j;
		pathY[i] = l;
		i--;
		for (k = 0; k < 4; k++)
		{
			int iy = l + dy[k];
			int ix = j + dx[k];
			if (iy >= 0 && iy < row && ix >= 0 && ix < column && grid[iy][ix] == i)
			{
				j = j + dx[k];
				l = l + dy[k];

				break;
			}
		}
	}
	pathX[0] = x1;
	pathY[0] = y1;
	return true;
}
