class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        seen = collections.defaultdict(list)
        degree = 0
        for i in range(len(nums)):
            seen[nums[i]].append(i)
            degree = max(len(seen[nums[i]]), degree)
        subarray_length = float('inf')
        for key in seen.keys():
            if len(seen[key]) == degree:
                subarray_length = min(seen[key][-1] - seen[key][0] + 1, subarray_length)
        return subarray_length
