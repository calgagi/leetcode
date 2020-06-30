class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        from collections import defaultdict
        seen = defaultdict(int)
        return self.backtrack(1, 1, m, n, seen)
        
    def backtrack(self, posX: int, posY: int, m: int, n: int, seen: dict) -> int:
        if posX == m and posY == n:
            return 1
        if seen[str([posX, posY])] != 0:
            return seen[str([posX, posY])]
        r = 0
        if posX < m:
            r += self.backtrack(posX+1, posY, m, n, seen)
        if posY < n:
            r += self.backtrack(posX, posY+1, m, n, seen)
        seen[str([posX, posY])] = r
        return r
