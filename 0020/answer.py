class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for i in s:
            if i == "{" or i == "(" or i == "[":
                stack.append(i)
            elif i == "}":
                if len(stack) == 0 or stack.pop() != "{":
                    return False
            elif i == "]":
                if len(stack) == 0 or stack.pop() != "[":
                    return False
            elif i == ")":
                if len(stack) == 0 or stack.pop() != "(":
                    return False
        if len(stack) == 0:
            return True
        else:
            return False

                
