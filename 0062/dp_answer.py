class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        r = [[0 for x in range(m+1)] for y in range(n+1)]
        r[1][0] = 1
        for x in range(1, m+1):
            for y in range(1, n+1):
                r[y][x] = r[y][x-1] + r[y-1][x]
        return r[n][m]
