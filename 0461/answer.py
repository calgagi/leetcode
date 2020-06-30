class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        num = 0
        x = "{0:b}".format(x)
        y = "{0:b}".format(y)
        x = "0"*(32-len(x)) + x
        y = "0"*(32-len(y)) + y
        for i in range(len(x)):
            if x[i] != y[i]:
                num += 1
        return num
