# Solution to Leetcode problem #387

class Solution:
    def firstUniqChar(self, s: 'str') -> 'int':
        seen = {}
        for i in range(len(s)):
            if s[i] not in seen:
                seen[s[i]] = i
            else:
                seen[s[i]] = None
        r = -1
        for x in seen.keys():
            if seen[x] != None:
                if r == -1:
                    r = seen[x]
                else:
                    r = min(r, seen[x])
        return r
