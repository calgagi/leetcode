class Solution:
    
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        r = []
        for s in strs:
            found = False
            for l in r:
                if self.anagram(s, l[0]):
                    l.append(s)
                    found = True
            if not found:
                r.append([s])
        return r
            
    
    def anagram(self, s1: str, s2: str) -> bool:
        from collections import defaultdict
        seen = defaultdict(int)
        for c in s1:
            seen[c] += 1
        for c in s2:
            if seen[c] == 0:
                return False
            seen[c] -= 1
        for c in seen:
            if seen[c] != 0:
                return False
        return True
