class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        sa = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 0:
                    sa += 2 # For top/bottom

                    if i-1 >= 0: # Check N
                        if grid[i][j] > grid[i-1][j]:
                            sa += grid[i][j] - grid[i-1][j]
                    else:
                        sa += grid[i][j]

                    if j-1 >= 0: # Check W
                        if grid[i][j] > grid[i][j-1]:
                            sa += grid[i][j] - grid[i][j-1]
                    else:
                        sa += grid[i][j]

                    if i+1 < len(grid): # Check S
                        if grid[i][j] > grid[i+1][j]:
                            sa += grid[i][j] - grid[i+1][j]
                    else:
                        sa += grid[i][j]

                    if j+1 < len(grid[0]): # Check E
                        if grid[i][j] > grid[i][j+1]:
                            sa += grid[i][j] - grid[i][j+1]
                    else:
                        sa += grid[i][j]
        return sa
