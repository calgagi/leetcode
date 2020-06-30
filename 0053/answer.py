class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        begin, end = 0, 1
        s = 0
        m = -999999999999
        while begin < end and end <= len(nums):
            s += nums[end-1]
            m = max(s, m)
            if s <= 0:
                begin = end
                s = 0
            end += 1
        return m
