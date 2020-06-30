class Solution:
    def countBits(self, num: int) -> List[int]:
        r = [0]
        for i in range(1, num+1):
            r.append((r[(i-1)&i]) + 1)
        return r
        
        
