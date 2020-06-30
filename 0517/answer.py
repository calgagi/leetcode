class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        num_candies = len(candies)
        sis_candies = num_candies // 2
        num_types = len(list(set(candies)))
        if sis_candies >= num_types:
            return num_types
        else:
            return sis_candies

        
