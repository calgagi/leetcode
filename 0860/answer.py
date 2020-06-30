class Solution(object):
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        bank = {
            5: 0,
            10: 0,
            20: 0
        }
        for i in bills:
            bank[i] += 1
            if i == 10:
                if bank[5] < 1:
                    return False
                bank[5] -= 1
            elif i == 20:
                if bank[5] >= 1 and bank[10] >= 1:
                    bank[5] -= 1
                    bank[10] -= 1
                elif bank[5] >= 3:
                    bank[5] -= 3
                else:
                    return False
        return True
