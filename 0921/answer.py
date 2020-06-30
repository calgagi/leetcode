class Solution:
    def minAddToMakeValid(self, S: 'str') -> 'int':
        stack = []
        for i in S:
            if i == "(":
                stack.append("(")
            elif i == ")":
                if len(stack) > 0 and stack[-1] == "(":
                    stack.pop()
                else:
                    stack.append(")")

        return len(stack)
