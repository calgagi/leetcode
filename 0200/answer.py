class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        num_islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    stack = [[i,j]]
                    num_islands += 1

                    while len(stack) != 0:
                        root = stack.pop()
                        grid[root[0]][root[1]] = "$"

                        # Check for sides, append to stack
                        if 0 < root[0] and grid[root[0]-1][root[1]] == "1":
                            stack.append([root[0]-1, root[1]])
                        if root[0] < len(grid)-1 and grid[root[0]+1][root[1]] == "1":
                            stack.append([root[0]+1, root[1]])
                        if root[1] < len(grid[0])-1 and grid[root[0]][root[1]+1] == "1":
                            stack.append([root[0], root[1]+1])
                        if 0 < root[1] and grid[root[0]][root[1]-1] == "1":
                            stack.append([root[0], root[1]-1])
        return num_islands:
