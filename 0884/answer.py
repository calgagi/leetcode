class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        from collections import defaultdict
        seen = defaultdict(int)
        A = A.split(" ")
        B = B.split(" ")
        rList = []
        for i in A:
            seen[i] += 1
        for j in B:
            seen[j] += 1
        for n in seen.keys():
            if seen[n] == 1:
                rList.append(n)
        return rList
        
