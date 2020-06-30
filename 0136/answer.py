class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        seenTwice = {}
        for num in nums:
            if num not in seenTwice:
                seenTwice[num] = 1
            else:
                seenTwice[num] = 2
        for key in seenTwice.keys():
            if seenTwice[key] == 1:
                return key
            
