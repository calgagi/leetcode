class Solution(object):
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        zpov, xpov, ypov = 0, 0, 0
        maxs_y = [0]*len(grid)
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] != 0:
                    zpov += 1
                if grid[x][y] > maxs_y[y]:
                    maxs_y[y] = grid[x][y]
            xpov += max(grid[x])
        ypov = sum(maxs_y)

        return xpov + ypov + zpov
