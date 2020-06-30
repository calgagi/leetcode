class Solution:
    def countSubstrings(self, s: str) -> int:
        r = 0
        for i in range(2*len(s)-1):
            center = i / 2
            left, right = int(center), int(center)
            if center % 1 == .5:
                right += 1
                
            while left >= 0 and right < len(s):
                if s[left] == s[right]:
                    r += 1
                else:
                    break
                left -= 1
                right += 1
        return r
                
