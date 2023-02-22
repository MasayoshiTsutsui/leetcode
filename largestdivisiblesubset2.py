from typing import List
DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        num_maxDivs = {}
        for i, num in enumerate(nums):
            maxDivs = []
            for j in range(i):
                if num % nums[j] == 0:
                    maxDivs = max([maxDivs, num_maxDivs[nums[j]]], key=len).copy()
            maxDivs.append(num)
            num_maxDivs[num] = maxDivs
        return max(num_maxDivs.values(), key=len)

nums = [1,2,4,8]
print(Solution().largestDivisibleSubset(nums))


        

"""
1,2,5,6,7,10,14,15,28,30
{1:[], 2:[1], 5:[1], 6: [1,2], 7: [1], 10: [1,2,5], 14: [1,2,7], 15: [1,5], 28: [1,2,7,14], 30: [1,5,15]}

1:1ko
2:2ko
5:2ko
6:3ko
7:2ko
10:3ko
14:3ko
15:3ko
28:4ko
30:4ko



"""