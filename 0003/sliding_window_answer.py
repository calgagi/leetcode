class Solution:
    def lengthOfLongestSubstring(self, s: 'str') -> 'int':
        table = {}

        ans, begin, end, counter = 0, 0, 0, 0

        while end < len(s):
            if s[end] in table:
                table[s[end]] += 1
                if table[s[end]] == 2:
                    counter += 1
            else:
                table[s[end]] = 1

            if counter == 0:
                ans = max(ans, (end-begin)+1)

            while counter > 0:
                if s[begin] in table:
                    table[s[begin]] -= 1
                    if table[s[begin]] == 1:
                        counter -= 1
                begin += 1
            end += 1
        return ans

                
