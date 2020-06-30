class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import defaultdict
        num_level = defaultdict(int)
        level = defaultdict(list)
        high = 1
        
        # setup
        for n in nums:
            num_level[n] += 1
            high = max(num_level[n], high)
            level[num_level[n]].append(n)
            if num_level[n] != 1:
                level[num_level[n]-1].remove(n)
        
        r = []
        # get stuff
        for x in range(k):
            while len(level[high]) == 0:
                high -= 1
            r.append(level[high].pop())
        return r
                
            
            
