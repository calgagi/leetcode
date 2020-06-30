class Solution(object):
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        if len(words) <= 1:
            return True
        for i in range(1, len(words)):
            previous_word = words[i-1]
            endofword = False
            for j in range(len(words[i])):
                if order.index(words[i][j]) < order.index(previous_word[j]):
                    return False
                elif order.index(words[i][j]) > order.index(previous_word[j]):
                    break
                endofword = True
            if endofword and len(words[i]) < len(previous_word):
                return False
        return True
