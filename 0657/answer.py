class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        lX, lY = 0, 0
        for i in moves:
            if i == "L":
                lX -= 1
            elif i == "R":
                lX += 1
            elif i == "U":
                lY += 1
            elif i == "D":
                lY -= 1
        if lY == 0 and lX == 0:
            return True
        else:
            return False
