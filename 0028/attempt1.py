class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0:
            return 0
        # Beginning spots of each potential string
        pR = []
        # For the number of elements in haystack, search for those characters
        for i in range(len(haystack)):
            if needle[0] == haystack[i]:
                pR.append(i)
        # If the next characters match, the string "stays" inside of the pR (list of possible Returns)
        # If not, remove that element from pR
        it = 0
        goodArray = []
        while len(needle) > it:
            goodArray = []
            for i in range(len(pR)):
                if it < len(needle) and pR[i]+it < len(haystack):
                    if haystack[pR[i]+it] == needle[it]:
                        goodArray.append(pR[i])
            pR = goodArray
            it += 1
            if len(pR) == 0:
                return -1
        return pR[0]
