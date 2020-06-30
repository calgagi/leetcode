class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        # CREATED BY ME WOO
        return [i for i in list(set(nums1)) if i in nums2]
