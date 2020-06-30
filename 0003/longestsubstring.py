class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Array of substrings
        substrings=[]
        # Return int
        longestSS = 0
        # For all characters in s
        for i in range(len(s)):
            # For all substrings
            for x in range(len(substrings)):
                # Check if character is in substring
                if s[i] not in substrings[x] and substrings[x][len(substrings[x])-1] != '\0':
                    substrings[x] += s[i]
                elif substrings[x][len(substrings[x])-1] != '\0':
                    substrings[x] += '\0'
            substrings.append(s[i])

        for i in range(len(substrings)):
            if substrings[i][len(substrings[i])-1] != '\0':
                substrings[i] += '\0'
            if longestSS < len(substrings[i]):
                longestSS = len(substrings[i].replace('\0', ""))
        return longestSS
