class Solution:
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        r, n0, n, prev = 0, 0, 0, s[0]
        if s[0] == "1":
            n1 = 1
        else:
            n0 = 1
        for i in range(1, len(s)):

                
