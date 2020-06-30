class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        r = []
        s = []
        self.backtrack(candidates, r, s, target, 0)
        return r
        
        
    def backtrack(self, candidates: List[int], r: List[List[int]], s: List[int], target: int, start: int) -> None:
        if len(s) != 0:
            if sum(s) == target:
                r.append(s.copy())
                return
            elif sum(s) > target:
                return
        for i in range(start, len(candidates)):
            s.append(candidates[i])
            self.backtrack(candidates, r, s, target, i)
            s.pop()
