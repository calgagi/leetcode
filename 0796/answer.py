class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if A == B:
            return True
        if len(A) != len(B):
            return False
        for i in range(len(B)):
            if A == B:
                return True
            A = A[-1] + A[:-1]
        return False
