class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        seen = {}
        for i in s:
            if i not in seen:
                seen[i] = 1
            else:
                seen[i] += 1
        for j in t:
            if j not in seen or seen[j] == 0:
                return j
            else:
                seen[j] -= 1

        
