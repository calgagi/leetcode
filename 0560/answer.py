class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        s = 0
        r = 0
        seen = collections.defaultdict(int)
        seen[0] = 1
        for i in range(len(nums)):
            s += nums[i]
            r += seen[s-k]
            seen[s] += 1
        return r
