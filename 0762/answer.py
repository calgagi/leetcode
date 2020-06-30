class Solution(object):
    def countPrimeSetBits(self, L, R):
        """
        :type L: int
        :type R: int
        :rtype: int
        """
        numP = 0
        for n in range(L, R+1):
            numOne = 0
            n = "{0:b}".format(n)
            for i in range(len(n)):
                if n[i] == "1":
                    numOne += 1
            if numOne in [2, 3, 5, 7, 11, 13, 17, 19]:
                numP += 1
        return numP
