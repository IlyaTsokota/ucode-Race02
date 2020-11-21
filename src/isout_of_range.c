#include "header.h"
void isout_of_range(int x1, int x2, int y1, int y2, int column, int row)
{
	if (x1 >= column || x2 >= column || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || y1 >= row || y2 >= row)
	{
		mx_printerr("points are out of map range\n");
		exit(0);
	}
}
