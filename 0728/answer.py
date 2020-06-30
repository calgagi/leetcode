class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        returnList = []
        for i in range(left, right+1):
            sdn = True
            for j in str(i):
                if j == "0" or i % int(j) != 0:
                    sdn = False
                    break
            if sdn == True:
                returnList.append(i)
        return returnList
        
