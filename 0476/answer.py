class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        num = "{0:b}".format(num)
        num_str = ""
        for i in num:
            if i == "0":
                num_str += "1"
            else:
                num_str += "0"
        return int(num_str, 2)
