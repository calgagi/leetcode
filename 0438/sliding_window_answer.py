class Solution:
    def findAnagrams(self, s: 'str', p: 'str') -> 'List[int]':
        # Create table
        table = {}
        for c in p:
            if c not in table:
                table[c] = 1
            else:
                table[c] += 1

        ans, begin, end, counter = [], 0, 0, len(table)
        length = len(p)

        while end < len(s):
            if s[end] in table:
                table[s[end]] -= 1
                if table[s[end]] == 0:
                    counter -= 1
            end += 1

            while counter == 0:
                if length == (end-begin):
                    ans.append(begin)
                if s[begin] in table:
                    table[s[begin]] += 1
                    if table[s[begin]] == 1:
                        counter += 1
                begin += 1
        return ans
            
