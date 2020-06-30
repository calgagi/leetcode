class Solution:
    def climbStairs(self, n: int) -> int:
        s = [0, 1, 2]
        for i in range(3, n+1):
            s.append(s[i-1]+s[i-2])
        return s[n]
