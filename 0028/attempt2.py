class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0:
            return 0
        for i in range(len(haystack)-len(needle)+1):
            bad = False
            for j in range(len(needle)):
                if haystack[i+j] != needle[j]:
                    bad = True
                    break
            if not bad:
                return i
        return -1


        
