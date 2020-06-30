class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        letters = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        alphabet = {}
        seen = {}
        num = 0
        for x in range(26):
            alphabet[chr(x+97)] = letters[x]

        for word in words:
            key = ""
            for i in word:
                key += alphabet[i]
            if key not in seen:
                num += 1
                seen[key] = True
        return num
