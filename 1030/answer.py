class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        r = []
        seen = collections.defaultdict(list)
        for i in range(R):
            for j in range(C):
                seen[abs(r0-i)+abs(c0-j)].append([i, j])
        key = 0
        while len(seen[key]) != 0:
            for x in seen[key]:
                r.append(x)
            key += 1
        return r
            
