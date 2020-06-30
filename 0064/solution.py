class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid) == 0:
            return 0
        memoization = [[0 for x in range(len(grid[0]))] for y in range(len(grid))]
        for i in range(0, len(memoization)):
            for j in range(0, len(memoization[0])):
                if i == 0 and j == 0:
                    memoization[i][j] = grid[i][j]
                elif i == 0:
                    memoization[i][j] = memoization[i][j-1] + grid[i][j]
                elif j == 0:
                    memoization[i][j] = memoization[i-1][j] + grid[i][j]
                else:
                    memoization[i][j] = min(memoization[i-1][j], memoization[i][j-1]) + grid[i][j]


        return memoization[len(memoization)-1][len(memoization[0])-1]
