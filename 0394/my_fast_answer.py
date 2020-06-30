class Solution:
    def decodeString(self, s: str) -> str:
        i, r = 0, ""
        while i < len(s):
            if "0" <= s[i] <= "9":
                num = s[i]
                while s[i+1] != "[":
                    i += 1
                    num += s[i]
                count, j = 1, i+2
                while count != 0:
                    if s[j] == "[":
                        count += 1
                    elif s[j] == "]":
                        count -= 1
                    if count == 0:
                        for x in range(int(num)):
                            r += self.decodeString(s[i+2:j])
                    j += 1
                i = j
            else:
                r += s[i]
                i += 1
        return r
                        
                
