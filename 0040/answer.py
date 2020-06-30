class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        r, s = [], []
        self.backtrack(candidates, target, r, s, 0)
        return r
        
    def backtrack(self, candidates: List[int], target: int, r: List[List[int]], s: List[int], start: int) -> None:
        if len(s) != 0:
            if sum(s) > target:
                return
            elif sum(s) == target:
                r.append(s.copy())
                return
        for i in range(start, len(candidates)):
            if i == start or candidates[i-1] != candidates[i]:
                s.append(candidates[i])
                self.backtrack(candidates, target, r, s, i+1)
                s.pop()

