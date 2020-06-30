class Solution:
    def findSubstring(self, s: 'str', words: 'List[str]') -> 'List[int]':
        master_table = {}
        for w in words:
            if w in master_table:
                master_table[w] += 1
            else:
                master_table[w] = 1

        if len(words) == 0 or len(words[0]) > len(s):
            return []

        ans, length = [], len(words[0])

        for i in range(length):
            begin, end = i, i
            table = dict(master_table)
            counter = len(table)

            while end < len(s):
                current_word = s[end:end+length]
                if current_word in table:
                    table[current_word] -= 1
                    if table[current_word] == 0:
                        counter -= 1

                while counter == 0:
                    if (end+length)-begin == length*len(words):
                        ans.append(begin)

                    current_word = s[begin:begin+length]
                    if current_word in table:
                        table[current_word] += 1
                        if table[current_word] == 1:
                            counter += 1

                    begin += length

                end += length
        return ans
                
