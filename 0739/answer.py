class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        r = [0]*len(T)
        for i in range(len(T)):
            while len(stack) != 0 and T[stack[-1]] < T[i]:
                idx = stack.pop()
                r[idx] = i - idx
            stack.append(i)
        return r
            
