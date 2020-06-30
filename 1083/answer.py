class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        r = []
        w = text.split(" ")
        for x in range(len(w)-2):
            if w[x] == first and w[x+1] == second:
                r.append(w[x+2])
        return r
