class Solution:
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        currLength = 1
        chunks = []
        r = 0
        for i in range(1, len(s)):
            if i > 0 and s[i] == s[i-1]:
                currLength += 1
            else:
                chunks.append(currLength)
                currLength = 1
        chunks.append(currLength)
        for i in range(1, len(chunks)):
            r += min(chunks[i], chunks[i-1])
        return r

                
