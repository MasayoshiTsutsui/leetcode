from typing import List

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        nums.sort()
        sum_cnt = [0] * (target + 1)
        sum_cnt[0] = 1

        for i in range(1, target + 1):
            for num in nums:
                if num > i:
                    break
                sum_cnt[i] += sum_cnt[i - num]
        
        return sum_cnt[target]

print(Solution().combinationSum4([1,2,3], 4))