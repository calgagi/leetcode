class Solution:
    def numSquares(self, n: int) -> int:
        self.a = []
        i, self.r = 1, float('inf')
        while (i*i) <= n:
            self.a.append(i*i)
            i += 1
        self.backtrack(n, 1)
        return self.r
    
    def backtrack(self, n: int, x: int) -> None:
        i = len(self.a)-1
        while self.a[i] > n and i > 0:
            i -= 1
        for j in range(0, i+1)[::-1]:
            if self.a[j] == n:
                self.r = min(x, self.r)
            else:
                self.backtrack(n-self.a[j], x+1)
