class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        output = ""
        if len(str) == 0:
            return 0
        if str[0] != '-' and str[0] != '+' and str[0] != ' ' and str[0].isdigit() != True:
            return 0

        hasNumber = False
        hasSign = False
        for i in range(len(str)):
            if output == "" and str[i] == '-' and hasSign == False:
                print(i)
                output += '-'
                hasSign = True
            if output == "" and str[i] == '+' and hasSign == False:
                print(i)
                hasSign = True
            if output != "" and hasSign == True and (str[i] == '-' or str[i] == '+'):
                return 0
            if hasNumber == True and str[i].isdigit() == False:
                break
            if str[i].isdigit():
                hasNumber = True
                output += str[i]

        if hasNumber == False:
            return 0

        outputInt = int(output)
        if outputInt > 2**31 - 1:
            return 2**31 - 1
        elif outputInt < -2**31:
            return -2**31
        return outputInt
