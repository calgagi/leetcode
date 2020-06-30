class RecentCounter(object):

    def __init__(self):
        self.pings = []

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        start = t - 3000
        self.pings.append(t)

        while True:
            x = self.pings.pop(0)
            if x >= start:
                self.pings = [x] + self.pings
                break


        return len(self.pings)



# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
