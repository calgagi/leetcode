class Solution:
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if len(word) <= 1:
            return True
        if ord(word[0]) >= 65 and ord(word[0]) <= 90:
            if ord(word[1]) >= 65 and ord(word[1]) <= 90:
                for i in range(1, len(word)):
                    if ord(word[i]) < 65 or ord(word[i]) > 90:
                        return False
                return True
            else:
                for i in range(1, len(word)):
                    if ord(word[i]) < 97 or ord(word[i]) > 122:
                        return False
                return True
        else:
            for i in range(1, len(word)):
                if ord(word[i]) < 97 or ord(word[i]) > 122:
                    return False
            return True
                    
