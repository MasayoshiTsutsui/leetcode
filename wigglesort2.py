from typing import List

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:

        nums.sort()

        smaller = nums[:(len(nums) + 1) // 2]
        larger = nums[(len(nums) + 1) // 2:]

        nums[0::2] = smaller[::-1]
        nums[1::2] = larger[::-1]