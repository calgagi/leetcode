class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        c = 0
        while n > 0:
            x = str(n % 2)
            n = n/2
            if x == "1":
                c += 1
        return c
