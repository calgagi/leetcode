class Solution(object):
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        Nend = len(S)
        Nstart = 0
        A = []
        for i in S:
            if i == "I":
                A.append(Nstart)
                Nstart += 1
            elif i == "D":
                A.append(Nend)
                Nend -= 1
        return A + [Nstart]
