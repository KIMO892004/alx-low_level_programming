#!/usr/bin/python3
"""This function returns the perimeter of the island"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island
    Args:
        grid => list of list of ints
    """
    perim = 0
    rws = len(grid)
    cols = len(grid[0])

    for r in range(rws):
        for c in range(cols):
            if grid[r][c] == 1:
                perim += 4

                if r > 0 and grid[r - 1][c] == 1:
                    perim -= 2
                if c > 0 and grid[r][c - 1] == 1:
                    perim -= 2
    return perim
