class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.r = [[]]
        for i in range(len(nums)):
            self.backtrack(nums, [nums[i]], i+1)
        return self.r
        
    def backtrack(self, nums: List[int], curr_list: List[int], index: int) -> None:
        self.r.append(curr_list.copy())
        for i in range(index, len(nums)):
            curr_list.append(nums[i])
            self.backtrack(nums, curr_list, i+1)
            curr_list.pop()
