class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        nums = 0
        for i in range(1, N+1):
            stri = str(i)
            valid1, valid2 = False, True
            for j in stri:
                if j in ["2", "5", "6", "9"]:
                    valid1 = True
                elif j not in ["1", "0", "8"]:
                    valid2 = False
                    break
            if valid1 and valid2:
                nums += 1
        return nums
