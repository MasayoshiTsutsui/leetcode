from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxOneCnt = 0
        seqOneCnt = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                seqOneCnt += 1
            else:
                maxOneCnt = max(maxOneCnt, seqOneCnt)
                seqOneCnt = 0
        maxOneCnt = max(maxOneCnt, seqOneCnt)

        return maxOneCnt

nums = [1,0,1,1,0,1]
print(Solution().findMaxConsecutiveOnes(nums))

