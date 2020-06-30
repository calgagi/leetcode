class Solution(object):
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if A == None or len(A) == 1:
            return True
        pattern = None
        for i in range(len(A)-1):
            if pattern == None:
                if A[i] > A[i+1]:
                    pattern = "Decreasing"
                elif A[i] < A[i+1]:
                    pattern = "Increasing"
            elif pattern == "Decreasing" and A[i] < A[i+1]:
                return False
            elif pattern == "Increasing" and A[i] > A[i+1]:
                return False
        return True
