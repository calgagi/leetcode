class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for i in A:
            for x in range(len(i)//2):
                if i[x] != i[(len(i)-1)-x]:
                    temp = i[x]
                    i[x] = i[len(i)-1-x]
                    i[len(i)-1-x] = temp
        for i in range(len(A)):
            for x in range(len(A[i])):
                if A[i][x] == 0:
                    A[i][x] = 1
                else:
                    A[i][x] = 0
        return A
                
