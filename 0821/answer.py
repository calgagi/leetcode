class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        occurences = []
        for s in range(len(S)):
            if S[s] == C:
                occurences.append(s)
        closest = 0
        rList = []
        for s in range(len(S)):
            if len(occurences) > closest+1 and abs(s - occurences[closest]) > abs(s - occurences[closest+1]):
                closest += 1
            rList.append(abs(s - occurences[closest]))
        return rList
