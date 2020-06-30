class Solution:
    def divisorGame(self, N: int) -> bool:
        turn = False
        while 1:
            not_found = True
            for i in range(1, N):
                if N % i == 0:
                    N -= i
                    turn = not turn
                    not_found = False
                    break
            if not_found:
                return turn
            
