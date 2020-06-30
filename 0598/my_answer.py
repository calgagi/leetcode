class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        x = [0]*m
        y = [0]*n
        for op in ops:
            x[op[0]-1] += 1
            y[op[1]-1] += 1
        
        
        xi,yi = 0,0
        for xi in range(m):
            if x[xi] != 0:
                break
        for yi in range(n):
            if y[yi] != 0:
                break
        return (yi+1)*(xi+1)
