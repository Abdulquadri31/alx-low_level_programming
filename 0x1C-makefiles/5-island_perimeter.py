#!/usr/bin/python3
"""
This module provides a function to calculate the perimeter
of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island in the given grid.

    Args:
        grid (list of list of int): A list of list of integers representing
        the grid, where 0 is water and 1 is land.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                # Add 4 for the current land cell
                perimeter += 4

                # Subtract 2 for each adjacent land cell
                if row > 0 and grid[row - 1][col] == 1:  # Check cell above
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] == 1:  # Check cell to the left
                    perimeter -= 2

    return perimeter
