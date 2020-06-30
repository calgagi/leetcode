class Solution:
    def countSubstrings(self, s: str) -> int:
        r = 0
        for l in range(len(s)):
            for i in range(len(s)-l):
                if s[i:i+l+1] == s[i:i+l+1][::-1]:
                    r += 1
        return r
