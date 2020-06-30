class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        r = []
        start_key = {}
        for i in pattern:
            start_key[i] = 0
        for word in words:
            curr_key = dict(start_key)
            valid = True
            for j in range(len(pattern)):
                if curr_key[pattern[j]] != word[j] and (curr_key[pattern[j]] != 0 or word[j] in curr_key.values()):
                    valid = False
                    break
                curr_key[pattern[j]] = word[j]
            if valid:
                r.append(word)
        return r
