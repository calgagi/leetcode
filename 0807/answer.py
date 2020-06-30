class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        max_lr, max_tb = [], [0]*len(grid[0])
        for i in grid:
            max_lr.append(max(i))
            for j in range(len(i)):
                max_tb[j] = max(i[j], max_tb[j])

        increase = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] < min(max_lr[i], max_tb[j]):
                    increase += min(max_lr[i], max_tb[j]) - grid[i][j]
        return increase
