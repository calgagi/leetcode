class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = 0 # Lower bound
        u = 0 # Upper bound
        h = {} # Hash map
        longest = 0 # Keep track of highest length

        # While there is still string left
        for u in range(len(s)):
            # If the character has been seen yet, set lower bound to either last seen spot or l depending on which is bigger
            if s[u] in h:
                l = max(l, h[s[u]])
            # If there is a new longest, set it to longest
            longest = max(longest, u-l+1)
            # Set last seen character to this index + 1
            h[s[u]] = u+1

        return longest
            
