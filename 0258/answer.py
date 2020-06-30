class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        numStr = str(num)
        while len(numStr) != 1:
            num = 0
            for i in numStr:
                num += int(i)
            numStr = str(num)
        return int(numStr)
