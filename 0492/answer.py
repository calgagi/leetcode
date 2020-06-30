class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        i = int(math.sqrt(area))
        while area % i != 0: 
            i -= 1
        return [max(i, int(area/i)), min(i, int(area/i))]
