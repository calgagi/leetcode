class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = 0
        for i, c in enumerate(s[::-1]):
            num += (((ord(c)-13) % 26)+1) * pow(26, i)
        return num
