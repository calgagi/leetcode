class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        nlines = 1
        cline = 100
        if S == None or S == "":
            return [0, 0]
        for i in S:
            if widths[ord(i)-97] <= cline:
                cline -= widths[ord(i)-97]
            else:
                cline = 100
                nlines += 1
                cline -= widths[ord(i)-97]
        return [nlines, 100-cline]
