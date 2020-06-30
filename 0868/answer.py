class Solution(object):
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N == 0:
            return 0
        longest, current = 0, 0
        N = "{0:b}".format(N)
        for i in N:
            if i == "1":
                longest = max(current, longest)
                current = 1
            else:
                current += 1
        return longest
