class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses = sorted(houses)
        heaters = sorted(heaters)
        min_radius = 0
        current_pos = 0
        for house in houses:
            for i in range(current_pos, len(heaters)):
                if abs(house - heaters[i]) <= abs(house - heaters[current_pos]):
                    current_pos = i
                    break
            min_radius = max(min_radius, abs(house - heaters[current_pos]))
        return min_radius
