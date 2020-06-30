class Solution:
    def fib(self, N: int) -> int:
        fib = [0,1]
        if N == 0 or N == 1:
            return fib[N]
        i = 2
        while i <= N:
            fib.append(fib[i-1] + fib[i-2])
            i += 1
        return fib[i-1]
        
