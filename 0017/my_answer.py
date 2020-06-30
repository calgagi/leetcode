class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        self.nums = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        self.r = []
        if len(digits) == 0:
            return self.r
        self.backtrack(digits, "")
        return self.r
        
    def backtrack(self, digits: str, curr: str) -> None:
        if len(digits) == 0:
            self.r.append(curr)
            return
        for c in self.nums[int(digits[0])]:
            self.backtrack(digits[1:], curr + c)
