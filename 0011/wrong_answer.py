class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_h = 0
        start_l = []
        area = 0
        for i, h in enumerate(height):
            if h > max_h:
                max_h = h
                start_l = [i]
            elif h == max_h:
                start_l.append(i)
        for index in start_l:
            for i, h in enumerate(height):
                if i != index and area < abs(index-i)*h:
                    area = abs(index-i)*h
        return area
