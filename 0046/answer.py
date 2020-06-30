class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.r = []
        self.backtrack([], nums)
        return self.r
            
    
    
    def backtrack(self, n: List[int], p: List[int]) -> None:
        if len(p) == 0:
            self.r.append(n.copy())
            return
        for i in range(len(p)):
            x = p.pop(i)
            n.append(x)
            self.backtrack(n, p)
            x = n.pop()
            p.insert(i, x)
