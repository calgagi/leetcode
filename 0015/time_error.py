class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        seen = {}
        r = []
        for i in nums:
            if i in seen:
                seen[i] += 1
            else:
                seen[i] = 1
        for k in seen.keys():
            seen[k] -= 1
            for j in seen.keys():
                if seen[j] >= 1:
                    seen[j] -= 1
                    if 0-(j+k) in seen and seen[0-(j+k)] >= 1:
                        x = sorted([k, j, 0-(j+k)])
                        if x not in r:
                            r.append(x)
                    seen[j] += 1
            seen[k] += 1
        return r
