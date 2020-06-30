class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        r = sorted([(x*x) for x in A])
        return r
