class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        countA, countB, count = 0, 0, len(costs)/2
        costs.sort(key=lambda t: abs(t[0] - t[1]))
        r = 0
        for cost in costs[::-1]:
            if max(countA, countB) < count:
                if cost[0] < cost[1]:
                    countA += 1
                    r += cost[0]
                else:
                    countB += 1
                    r += cost[1]
            elif countB < count:
                r += cost[1]
            elif countA < count:
                r += cost[0]
        return r
        
        
        
