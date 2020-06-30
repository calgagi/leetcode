class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        arrays = []
        for i in range(len(A[0])):
            arrays.append([s[i] for s in A])
        r = 0
        for i in range(len(arrays)):
            if sorted(arrays[i]) != arrays[i]:
                r += 1
        return r
