class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        r = [[]]
        for i in range(len(nums)):
            for j in range(pow(2, i)):
                s = r[j].copy()
                s.append(nums[i])  
                r.append(s)
        return r
                
