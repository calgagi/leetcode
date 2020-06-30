class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        val = 0
        for i in range(len(s)):
            if s[i] == "I":
                if i+1 < len(s) and (s[i+1] == "V" or s[i+1] == "X"):
                    val -= 1
                else:
                    val += 1
            elif s[i] == "X":
                if i+1 < len(s) and (s[i+1] == "L" or s[i+1] == "C"):
                    val -= 10
                else:
                    val += 10
            elif s[i] == "C":
                if i+1 < len(s) and (s[i+1] == "D" or s[i+1] == "M"):
                    val -= 100
                else:
                    val += 100
            elif s[i] == "V":
                val += 5
            elif s[i] == "L":
                val += 50
            elif s[i] == "D":
                val += 500
            elif s[i] == "M":
                val += 1000
        return val
