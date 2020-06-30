class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        minimum = float("inf")
        A.sort()
        for i in range(len(A)):
            if A[i] < 0:
                A[i] *= -1
                K -= 1
            if K == 0:
                return sum(A)
            minimum = min(minimum, A[i])
        if K % 2 == 0:
            return sum(A)
        else:
            return sum(A)-(2*minimum)
