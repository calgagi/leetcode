class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        returnList = []
        for i in range(1, n+1):
            if i % 3 == 0 and i % 5 == 0:
                returnList.append("FizzBuzz")
            elif i % 3 == 0:
                returnList.append("Fizz")
            elif i % 5 == 0:
                returnList.append("Buzz")
            else:
                returnList.append(str(i))
        return returnList
                
