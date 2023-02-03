from typing import List
class Solution:

    def findCertainSizeMax(self, nums: List[int], num_to_pick: int) -> List[int]:
        ans = []
        ith_num_idx = -1
        #print(f"num_to_pick: {num_to_pick}")
        #print("")
        for i in range(1, num_to_pick + 1):
            begin = ith_num_idx + 1
            end = len(nums) - (num_to_pick - i)
            if not begin < end:
                break
            #print(f"i: {i}")
            #print(f"begin: {begin}")
            #print(f"end: {end}")
            #print("")
            ith_num_idx = max(range(begin, end), key=nums.__getitem__)
            ans.append(nums[ith_num_idx])
        return ans
    
    def merge(self, max1: List[int], max2: List[int]) -> List[int]:
        ans = []
        idx1 = 0
        idx2 = 0

        while idx1 < len(max1) or idx2 < len(max2):
            if max1[idx1:] > max2[idx2:]:
                ans.append(max1[idx1])
                idx1 += 1
            else:
                ans.append(max2[idx2])
                idx2 += 1
        return ans


    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        maxNum = [-1 for _ in range(k)]
        for i in range(k+1):
            num_to_pick1 = i
            num_to_pick2 = k - i

            max1 = self.findCertainSizeMax(nums1, num_to_pick1)
            max2 = self.findCertainSizeMax(nums2, num_to_pick2)
            if len(max1) != num_to_pick1 or len(max2) != num_to_pick2:
                continue
            print(f"max1: {max1}")
            print(f"max2: {max2}")
            ithmax = self.merge(max1, max2)
            print(f"ithmax: {ithmax}")
            maxNum = max(ithmax, maxNum)
        return maxNum