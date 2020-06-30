class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        hare, tortoise = nums[nums[0]], nums[0]
        while hare != tortoise:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
        
        hare = 0
        while hare != tortoise:
            hare = nums[hare]
            tortoise = nums[tortoise]
        
        return hare
        
            
