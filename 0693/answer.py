class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        n = "{0:b}".format(n)
        for i in range(len(n)-1):
            if n[i] == n[i+1]:
                return False
        return True
        
