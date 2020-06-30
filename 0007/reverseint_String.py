class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        strX = str(x)
        if strX[0] == '-':
            strXReversed = '-' + strX[:0:-1]
        else:
            strXReversed = strX[::-1]
        if(abs(int(strXReversed)) > (2 ** 31 - 1)):
            return 0
        return int(strXReversed)
