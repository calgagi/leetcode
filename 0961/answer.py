class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        from collections import defaultdict
        hashmap = defaultdict(int)
        
        for a in A:
            hashmap[a] += 1
            if hashmap[a] == len(A)/2:
                return a
