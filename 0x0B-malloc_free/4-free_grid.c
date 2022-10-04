#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid (array)
 * @grid: the 2d array
 * @height: number of row
 *
 * Return: Allways void.
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(*(grid + i));

	free(grid);
}
