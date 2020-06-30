class Solution:
    def numDecodings(self, s: str) -> int:
        l, r = len(s), [0 for i in range(len(s)+1)]
        if l == 0:
            return 0
        if s[0] == "0":
            return 0
    
        r[0] = 1
        r[1] = 1
        for i in range(1, len(s)):
            if (s[i-1] == "1" and s[i] <= "9") or (s[i-1] == "2" and s[i] <= "6"):
                r[i+1] += r[i-1]
            if "1" <= s[i] <= "9":
                r[i+1] += r[i]
        return r[-1]                
        
        
