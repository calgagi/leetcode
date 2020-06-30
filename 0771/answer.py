class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        num_jewels = 0
        for j in J:
            for s in S:
                if s == j:
                    num_jewels += 1
        return num_jewels
