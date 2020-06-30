class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        seen = {}
        if nums[0] == 0:
            seen[0] = 2
        else:
            seen[nums[0]] = seen[-nums[0]] = 1
        
        for i in range(1, len(nums)):
            temp = {}
            for num in seen:
                temp[num + nums[i]] = temp.get(num + nums[i], 0) + seen.get(num, 0)
                temp[num - nums[i]] = temp.get(num - nums[i], 0) + seen.get(num, 0)
            seen = temp
        return seen.get(S, 0)

