class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.r = []
        self.backtrack(n, 0, "")
        return self.r
        
        
    def backtrack(self, num_s: int, num_c: int, curr: str) -> None:
        if num_s == num_c == 0:
            self.r.append(curr)
            return
        if num_s > 0:
            curr += "("
            self.backtrack(num_s-1, num_c+1, curr)
            curr = curr[:-1]
        if num_c > 0:
            curr += ")"
            self.backtrack(num_s, num_c-1, curr)
            curr = curr[:-1]
            
