class Solution(object):
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sumA = sum(A)
        sumB = sum(B)
        dif = (sumA - sumB)/2
        seenA = {}
        for j in A:
            seenA[j] = j
        for i in B:
            if dif+i in seenA:
                return [dif+i, i]
