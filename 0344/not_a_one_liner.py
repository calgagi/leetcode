class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        rString = list(s)
        start, end = 0, len(s)-1

        while start < end:
            temp = rString[start]
            rString[start] = rString[end]
            rString[end] = temp
            start += 1
            end -= 1
        return "".join(rString)
