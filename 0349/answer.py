class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        from collections import defaultdict
        seen1 = defaultdict(int)
        rlist = []
        for i in nums1:
            seen1[i] = 1
        for j in nums2:
            if seen1[j] == 1 and j not in rlist:
                rlist.append(j)
        return rlist
            
