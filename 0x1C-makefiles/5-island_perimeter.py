#!/usr/bin/python3
"""Island Perimeter module.
"""

# 1- Loop through the grid list and find the first land.
# 2- Starting from the first land get the island's height and width.
#    if no land found then height = width = 0.
# The perimeter is equal to 2 * (height + width).


def island_perimeter(grid):
    """
        Returns the perimeter of the island described in grid.

        grid is a list of list of integers.
          - 0 represents a water zone.
          - 1 represents a land zone.
          - One cell is a square with side length 1.
          - Grid cells are connected horizontally/vertically (not diagonally).
          - Grid is rectangular, width and height don’t exceed 100.

        Grid is completely surrounded by water, and there is one island
        (or nothing).

        The island doesn’t have “lakes” (water inside that isn’t
        connected to the water around the island).

        Args:
            grid (list(list(int))): The grid.
    """
    i = j = None
    w = h = 0

    if grid is None or len(grid) == 0:
        return (0)

    gwidth = len(grid)
    gheight = len(grid[0])
    for x in range(gwidth):
        for y in range(gheight):
            if grid[x][y] == 1:
                i = x
                j = y
                break
        if i is not None:
            break

    if i is None:
        return (0)

    for x in range(i, gwidth):
        for y in range(j, gheight):
            y1 = y + 1
            if y1 < gheight and grid[x][y1] == 1:
                h += 1
            else:
                break
        if h > 0:
            break
    h = h + 1 if h > 0 else h

    for y in range(j, gheight):
        for x in range(i, gwidth):
            x1 = x + 1
            if x1 < gwidth and grid[x1][y] == 1:
                w += 1
            else:
                break
        if w > 0:
            break
    w = w + 1 if w > 0 else w

    return 2 * (w + h)
