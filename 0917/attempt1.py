class Solution(object):
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        end = len(S)-1
        start = 0
        while start < end:
            if S[start].isalpha() and S[end].isalpha():
                S = S[0:start-1] + S[end] + S[start+1:end-1] + S[start] + S[end:len(S)-1]
                end -= 1
            else:
                while start < end and not S[start].isalpha():
                    start += 1
                while start < end and not S[end].isalpha():
                    end -= 1
        return S
