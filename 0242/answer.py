class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        count = {}

        for i in s:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        for i in t:
            if i not in count:
                return False
            count[i] -= 1
            if count[i] < 0:
                return False
        for i in count:
            if count[i] != 0:
                return False
        return True
