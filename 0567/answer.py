class Solution:
    def checkInclusion(self, s1: 'str', s2: 'str') -> 'bool':
        table = {}
        for c in s1:
            if c in table:
                table[c] += 1
            else:
                table[c] = 1

        begin, end, counter = 0, 0, len(table)

        while end < len(s2):
            if s2[end] in table:
                table[s2[end]] -= 1
                if table[s2[end]] == 0:
                    counter -= 1
            end += 1

            while counter == 0:
                if len(s1) == (end-begin):
                    return True

                if s2[begin] in table:
                    table[s2[begin]] += 1
                    if table[s2[begin]] == 1:
                        counter += 1

                begin += 1

        return False
