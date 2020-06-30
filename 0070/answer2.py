class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        r = [1, 1, 2]
        for i in range(3, n+1):
            r.append(r[i-1]+r[i-2])
        return r[n]
