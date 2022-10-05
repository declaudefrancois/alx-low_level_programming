#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: number of columns.
 * @height: number of rows.
 *
 * Return: a pointer to int **
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j, k;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **) malloc(sizeof(int *) * height);
	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		*(grid + i) = (int *) malloc(sizeof(int) * width);
		if (*(grid + i) == NULL)
		{
			for (k = 0; k <= i; k++)
				free(grid[k]);
			free(grid);

			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			grid[i][j] = 0;

	return (grid);
}
