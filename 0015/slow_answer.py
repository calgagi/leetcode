class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        seen = {}
        for i,n in enumerate(nums):
            if n not in seen:
                seen[n] = [i]
            else:
                seen[n].append(i)
                
        r = []
        sets = []
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                k = 0-nums[i]-nums[j]
                if k in seen.keys():
                #i not in seen[k] and j not in seen[k]:
                    if len(seen[k]) >= 3 or (i not in seen[k] and j not in seen[k]):
                        if set([k, nums[i], nums[j]]) not in sets:
                            sets.append(set([k, nums[i], nums[j]]))
                            r.append([k, nums[i], nums[j]])
        return r
                
