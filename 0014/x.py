class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        output = ""
        for i in range(len(strs[0])):
            alltrue = True
            charCompare = strs[0][i]
            for j in range(len(strs)):
                if strs[j][i] != charCompare:
                    alltrue = False
                    break
            if alltrue == True:
                output += charCompare
            else:
                break
        return output
