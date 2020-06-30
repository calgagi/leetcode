class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        returnList = []
        low = 0
        high = len(nums)
        if high == 0:
            return [-1,-1]
        mid = -1


        while low < high:
            mid = ((high-low)//2) + low

            if nums[mid] > target:
                high = mid
            elif nums[mid] < target:
                if low == mid:
                    break
                low = mid
            else:
                break

        if nums[mid] != target:
            return [-1,-1]

        i = 0
        while i <= max(mid, len(nums)-1-mid):
            if mid-i >= 0:
                if nums[mid-i] == target:
                    low = mid-i
            if mid+i < len(nums):
                if nums[mid+i] == target:
                    high = mid+i
            i += 1

        returnList.append(low)
        returnList.append(high)
        return returnList
