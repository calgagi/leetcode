class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        r = []
        c = []
        for i in range(n):
            c.append(list("."*n))
        self.backtrack(r, n, c, 0)
        return r
        
    def backtrack(self, r: List[List[str]], n: int, c: List[str], s: int) -> None:
        for i in range(n):
            c[s][i] = "Q"
            if self.is_valid(c):
                if s == n-1:
                    x = []
                    for b in range(len(c)):
                        x.append("".join(c[b])) 
                    r.append(x.copy())
                else:
                    self.backtrack(r, n, c, s+1)
            c[s][i] = "."
    
    def is_valid(self, c: List[str]) -> bool:
        countY = [0]*len(c)
        # Check X
        for i in range(len(c)):
            countX = 0
            for j in range(len(c[i])):
                if c[i][j] == "Q":
                    countX += 1
                    countY[j] += 1
                    # Check diagonals
                    for d in range(1, len(c)):
                        if i-d >= 0 and j-d >= 0 and c[i-d][j-d] == "Q":
                            return False
                        if i+d < len(c) and j+d < len(c) and c[i+d][j+d] == "Q":
                            return False
                        if i-d >= 0 and j+d < len(c) and c[i-d][j+d] == "Q":
                            return False
                        if i+d < len(c) and j-d >= 0 and c[i+d][j-d] == "Q":
                            return False
            if countX > 1:
                return False
        # Check Y
        for i in range(len(c)):
            if countY[i] > 1:
                return False
        return True
            
        
