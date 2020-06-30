class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        r = []
        s = []
        self.backtrack(r, s, nums, 0)
        return r
    
    def backtrack(self, r: List[int], s: List[int], nums: List[int], start: int) -> None:
        r.append(s.copy())
        
        for j in range(start, len(nums)):
            if j == start or nums[j] != nums[j-1]:
                s.append(nums[j])
                self.backtrack(r, s, nums, j+1)
                s.pop()
        
