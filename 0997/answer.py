class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        is_trusted = collections.defaultdict(list)
        trusts = collections.defaultdict(list)
        for t in trust:
            trusts[t[0]].append(t[1])
            is_trusted[t[1]].append(t[0])
        l = []
        for i in range(N):
            if len(trusts[i+1]) == 0:
                l.append(i+1)
        if len(l) == 0:
            return -1
        l2 = []
        for j in l:
            if len(is_trusted[j]) == N-1:
                l2.append(j)
        if len(l2) == 1:
            return l2[0]
        else:
            return -1
            
            
