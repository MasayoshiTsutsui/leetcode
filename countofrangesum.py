from typing import List
from bisect import bisect_left, bisect_right
import logging


DEBUG = True

def dbg_print(s):
    if DEBUG:
        print(s)


class Solution:

    def mergesort_count(self, nums: List[int], lower: int, upper: int):
        logging.basicConfig(level=logging.DEBUG, format='%(levelname)s: %(message)s')
        if len(nums) == 1:
            if lower <= nums[0] <= upper:
                return nums, 1
            else:
                return nums, 0

        mid = len(nums) // 2

        left_sorted, left_cnt = self.mergesort_count(nums[:mid], lower, upper)
        right_sorted, right_cnt = self.mergesort_count(nums[mid:], lower, upper)

        cnt = left_cnt + right_cnt
        dbg_print(f"left_sorted: {left_sorted}")
        dbg_print(f"right_sorted: {right_sorted}")
        dbg_print(f"cnt: {cnt}")
        dbg_print("")
        

        for left in left_sorted:
            lower_idx = bisect_left(right_sorted, lower + left)
            upper_idx = bisect_right(right_sorted, upper + left)
            cnt += upper_idx - lower_idx
            #dbg_print(f"lower_idx: {lower_idx}")
            #dbg_print(f"upper_idx: {upper_idx}")
            #dbg_print(f"left: {left}")
            #dbg_print(f"right_sorted: {right_sorted}")
            #dbg_print(f"cnt: {cnt}")
            #dbg_print("")
        
        nums_sorted = sorted(left_sorted + right_sorted)

        assert len(nums_sorted) == len(nums)

        return nums_sorted, cnt

    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        accum_sums = []
        sum = 0
        for num in nums:
            sum += num
            accum_sums.append(sum)
        _, cnt = self.mergesort_count(accum_sums, lower, upper)
        return cnt
        

"""
num = [-2, 5, -1]
accum = [-2, 3, 2]

[0, 0] = accum[0] - accum[-1]
[0, 1] = accum[1] - accum[-1]
[0, 2] = accum[2] - accum[-1]
[2, 2] = accum[2] - accum[1]

[-2,3,2]
"""