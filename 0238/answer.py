class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        r = []
        x = 1
        for i in range(len(nums)):
            r.append(x)
            x = r[i]*nums[i]
        
        x = 1
        for j in range(len(nums))[::-1]:
            r[j] *= x
            x *= nums[j]
        return r
