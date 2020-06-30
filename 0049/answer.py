class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import defaultdict
        r = []
        strs_sorted = []
        x = defaultdict(list)
        
        for s in strs:
            if s != "":
                s = "".join(sorted(list(s)))
            strs_sorted.append(s)
            
        for s in range(len(strs)):
            x[strs_sorted[s]].append(strs[s])
        
        for s in x:
            r.append(x[s])
        return r
