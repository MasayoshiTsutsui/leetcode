from typing import List, Tuple



class Solution:
    @staticmethod
    def mergeSort_counter(nums_idx: List[Tuple[int, int]]) -> Tuple[List[int], List[int]]:
        if len(nums_idx) <= 1:
            return nums_idx, [0 for _ in range(len(nums_idx))]
        mid = len(nums_idx) // 2
        left_merged, left_cnts = Solution.mergeSort_counter(nums_idx[:mid])
        right_merged, right_cnts = Solution.mergeSort_counter(nums_idx[mid:])
        merged_nums_idx = []
        merged_cnts = []
        left_idx = 0
        right_idx = 0

        num_smaller_in_right = 0

        while left_idx != len(left_merged) or right_idx != len(right_merged):
            smallest_in_left = 99999999
            smallest_in_right = 99999999
            smallest_in_left_idx = 99999999
            smallest_in_right_idx = 99999999
            if left_idx != len(left_merged):
                smallest_in_left, smallest_in_left_idx = left_merged[left_idx]
                cnt_left = left_cnts[left_idx]
            if right_idx != len(right_merged):
                smallest_in_right, smallest_in_right_idx = right_merged[right_idx]
                cnt_right = right_cnts[right_idx]
            
            if smallest_in_left <= smallest_in_right:
                merged_nums_idx.append((smallest_in_left, smallest_in_left_idx))
                merged_cnts.append(cnt_left + num_smaller_in_right)
                left_idx += 1
            else:
                merged_nums_idx.append((smallest_in_right, smallest_in_right_idx))
                merged_cnts.append(cnt_right)
                num_smaller_in_right += 1
                right_idx += 1
        #print(f"nums_idx: {nums_idx}")
        #print(f"left_merged: {left_merged}")
        #print(f"right_merged: {right_merged}")
        #print(f"merged_nums_idx: {merged_nums_idx}")
        #print(f"merged_cnts: {merged_cnts}")
        #print("")

        return merged_nums_idx, merged_cnts


    def countSmaller(self, nums: List[int]) -> List[int]:
        nums_idx = [(num, idx) for idx, num in enumerate(nums)]
        ans = [0 for _ in range(len(nums))]
        nums_idx, cnts = Solution.mergeSort_counter(nums_idx)

        for (num, idx), cnt in zip(nums_idx, cnts):
            ans[idx] = cnt
        
        return ans
