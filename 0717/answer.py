class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        c = 0
        for i in range(0,len(bits)-1)[::-1]:
            if bits[i] == 1:
                c += 1
            else:
                break
        if c % 2 == 1:
            return False
        else:
            return True
