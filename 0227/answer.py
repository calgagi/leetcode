class Solution:
    def calculate(self, s: 'str') -> 'int':
        nums = []
        ops = []
        j = 0
        while j < len(s):
            if s[j] == "*" or s[j] == "/" or s[j] == "+" or s[j] == "-":
                ops += s[j]
            elif s[j] <= "9" and s[j] >= "0":
                size = 0
                while j+size < len(s):
                    if s[j+size] <= "9" and s[j+size] >= "0":
                        size += 1
                    else:
                        break
                nums.append(int(s[j:(j+size)]))
                j += size-1
            j += 1
        print(nums, ops)
        j = 0
        while j < len(ops):
            if ops[j] == "*":
                nums[j] = nums[j] * nums[j+1]
                nums.pop(j+1)
                ops.pop(j)
                j -= 1
            elif ops[j] == "/":
                nums[j] = int(nums[j] / nums[j+1])
                nums.pop(j+1)
                ops.pop(j)
                j -= 1
            j += 1

        j = 0
        while j < len(ops):
            if ops[j] == "+":
                nums[j] = nums[j] + nums[j+1]
                nums.pop(j+1)
                ops.pop(j)
                j -= 1
            elif ops[j] == "-":
                nums[j] = nums[j] - nums[j+1]
                nums.pop(j+1)
                ops.pop(j)
                j -= 1
            j += 1
        return nums[0]
