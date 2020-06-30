class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        q = [[r0, c0]]
        o = grid[r0][c0]
        r = []
        for i in range(len(grid)):
            r.append(grid[i].copy())
        while len(q) != 0:
            c = q.pop(0)
            grid[c[0]][c[1]] = 0
            if c[0] > 0 and grid[c[0]-1][c[1]] == o:
                q.append([c[0]-1, c[1]])
            if c[1] > 0 and grid[c[0]][c[1]-1] == o:
                q.append([c[0], c[1]-1])
            if c[0] < len(grid)-1 and grid[c[0]+1][c[1]] == o:
                q.append([c[0]+1, c[1]])
            if c[1] < len(grid[0])-1 and grid[c[0]][c[1]+1] == o:
                q.append([c[0], c[1]+1])
        print(grid)
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0 and (i == 0 or i == len(grid)-1 or j == 0 or j == len(grid[0])-1):
                    r[i][j] = color
                elif i == 0 or i == len(grid)-1 or j == 0 or j == len(grid[0])-1:
                    continue
                elif grid[i][j] == 0 and (grid[i-1][j] != 0 or grid[i+1][j] != 0 or grid[i][j-1] != 0 or grid[i][j+1] != 0):
                    r[i][j] = color
        return r
        
