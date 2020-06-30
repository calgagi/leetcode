class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(" ")
        rString = ""
        for i in range(len(words)):
            rString += words[i][::-1]
            if i != len(words)-1:
                rString += " "
        return rString

        
