class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        odds = []
        evens = []
        for i in A:
            if i % 2 == 0:
                evens.append(i)
            else:
                odds.append(i)
        switch = True
        rList = []
        for i in range(len(A)):
            if switch:
                rList.append(evens.pop())
            else:
                rList.append(odds.pop())
            switch = not switch
        return rList
        
