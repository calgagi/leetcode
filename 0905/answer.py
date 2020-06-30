class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        arrayEven = []
        arrayOdd = []
        for i in A:
            if i % 2 == 0:
                arrayEven.append(i)
            else:
                arrayOdd.append(i)

        return arrayEven + arrayOdd
