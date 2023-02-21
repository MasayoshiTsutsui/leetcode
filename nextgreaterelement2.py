
from typing import List


class Solution:

    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []
        idxStack = [0]
        ans = [-1] * len(nums)

        for i in range(1, len(nums)):
            while len(idxStack) > 0 and nums[idxStack[-1]] < nums[i % len(nums)]:
                ans[idxStack[-1]] = nums[i % len(nums)]
                idxStack.pop()
            idxStack.append(i % len(nums))
        
        while len(idxStack) > 0 and nums[idxStack[-1]] < nums[0]:
            ans[idxStack[-1]] = nums[i % len(nums)]
            idxStack.pop()
        return ans

nums = [1,2,]
print(Solution().nextGreaterElements(nums))


"""

1,2,3,4,6,5,1
5,5,5,5

-1,3,4,5,3,5,5

"""
