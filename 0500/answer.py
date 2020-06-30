class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        rList = []
        for or_word in words:
            row = -1
            word = or_word.lower()
            if word[0] in rows[0]:
                row = 0
            elif word[0] in rows[1]:
                row = 1
            elif word[0] in rows[2]:
                row = 2
            for letter in word:
                if letter not in rows[row]:
                    row = -1
                    break
            if row != -1:
                rList.append(or_word)
        return rList
                
