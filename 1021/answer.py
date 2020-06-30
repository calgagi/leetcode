class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        r = ""
        stack = 0
        for s in S:
            if s == "(":
                if stack:
                    r += "("
                stack += 1
            elif s == ")":
                if stack-1:
                    r += ")"
                stack -= 1
        return r
