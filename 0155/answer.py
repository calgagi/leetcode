class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min = -1
        

    def push(self, x: int) -> None:
        if len(self.stack) == 0:
            self.min = 0
        elif self.stack[self.min] > x:
            self.min = len(self.stack)
        self.stack.append(x)

    def pop(self) -> None:
        r = self.stack.pop()
        if self.min == len(self.stack) and len(self.stack) != 0:
            self.min = self.stack.index(min(self.stack))
        return r

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.stack[self.min]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
