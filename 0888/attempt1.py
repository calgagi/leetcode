class Solution(object):
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sumA = sum(A)
        sumB = sum(B)
        for i in A:
            for j in B:
                if sumA-i+j == sumB-j+i:
                    return [i, j]
                
