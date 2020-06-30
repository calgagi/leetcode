class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        else:
            prev = self.countAndSay(n-1)
            r = ""
            counter, p = 0, prev[0]
            for i in range(0, len(prev)):
                if prev[i] == p:
                    counter += 1
                else:
                    r += str(counter)+p
                    counter = 1
                    p = prev[i]
            r += str(counter)+p
            return r
        
