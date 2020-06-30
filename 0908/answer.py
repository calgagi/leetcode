class Solution(object):
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        if len(A) == 1:
            return 0

        mi = min(A)
        ma = max(A)

        if ((ma-K) - (mi+K)) <= 0:
            return 0
        else:
            return ((ma-K) - (mi+K))

        
