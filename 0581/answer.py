class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        sortedarray = sorted(nums)
        begin = 0
        end = len(nums)-1
        while begin <= end:
            if nums[begin] != sortedarray[begin]:
                break
            begin += 1
        while begin <= end:
            if nums[end] != sortedarray[end]:
                break
            end -= 1
        return end-begin+1
                
        
