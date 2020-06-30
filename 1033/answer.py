class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        r = sorted([a, b, c])
        a, b, c = r[0], r[1], r[2]
        x = [0, (b-1-a) + (c-1-b)]
        if a == c-2:
            return x
        if b-a <= 2 or c-b <= 2:
            x[0] = 1
            return x
        else:
            x[0] = 2
            return x
            
