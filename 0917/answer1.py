class Solution(object):
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        NOTE TO SELF: TRY TO USE A STACK MAYBE?
        """
        end = len(S)-1
        start = 0
        while start < end:
            while start < end and not S[start].isalpha():
                start += 1
            while start < end and not S[end].isalpha():
                end -= 1
            if start < end:
                Slist = list(S)
                Slist[start], Slist[end] = Slist[end], Slist[start]
                S = "".join(Slist)
                start += 1
                end -= 1
        return S
