class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        p = 0
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] == 1:
                    if y+1 >= len(grid[0]) or grid[x][y+1] == 0:
                        p += 1
                    if y-1 < 0 or grid[x][y-1] == 0:
                        p += 1
                    if x+1 >= len(grid) or grid[x+1][y] == 0:
                        p += 1
                    if x-1 < 0 or grid[x-1][y] == 0:
                        p += 1
        return p
