class Solution:
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        min_len = 16
        word = ""
        licensePlateLetters = []
        for char in licensePlate:
            if char.isalpha():
                licensePlateLetters.append(char.lower())
        licensePlateLetters = "".join(licensePlateLetters)
        for i in range(len(words)):
            valid = True
            for j in licensePlateLetters:
                if words[i].count(j) < licensePlateLetters.count(j):
                    valid = False
                    break
            if valid and len(words[i]) < min_len:
                min_len = len(words[i])
                word = words[i]
        return word

        
