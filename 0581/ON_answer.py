class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        begin, end, minv, maxv = -1, -2, nums[len(nums)-1], nums[0]
        
        for i in range(1, len(nums)):
            maxv = max(nums[i], maxv)
            minv = min(nums[len(nums)-1-i], minv)
            if maxv > nums[i]:
                end = i
            if minv < nums[len(nums)-1-i]:
                begin = len(nums)-i-1
            
        return end-begin+1
        
