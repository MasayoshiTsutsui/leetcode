from typing import List
import copy

DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)



class Solution:

    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()

        #divisor_cnt_map = {}
        dividant_divisors_map = {}

        for i in range(len(nums)):
            dividant = nums[i]
            dividant_divisors_map[dividant] = [dividant]
            for j in range(i):
                divisor = nums[j]
                if dividant % divisor == 0:
                    assert divisor in dividant_divisors_map
                    if len(dividant_divisors_map[dividant]) < len(dividant_divisors_map[divisor]) + 1:
                        dividant_divisors_map[dividant] = [dividant]
                        dividant_divisors_map[dividant].extend(dividant_divisors_map[divisor])
            
        
        ans = []
        dbg_print(f"dividant_divisors_map: {dividant_divisors_map}")
        for subset in dividant_divisors_map.values():
            if len(ans) < len(subset):
                ans = subset
        
        return ans




