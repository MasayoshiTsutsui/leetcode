
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        return

"""
nums = [1,5,10]
possible_sum = [1, 5, 6, 10, 11, 15, 16]
rest_sum = [2, 3, 4, 7, 8, 9, 12, 13, 14, 17, 18, 19, 20]

patch 2

possible_sum = [1, 3, 5, 6, 7, 8, 10, 11, 12, 13, 15, 16]


---------------------

n = 30
nums = [1,3,11]
possible_sum = [1, 3, 4, 11, 12, 14, 15]
rest_sum = [2, 5, 6, 7, 8, 9, 10, 13, 16, 17, ...30]

add 2
possible_sum = [1, 2, 3, 4, 5, 6, 11, 12, 13, 14, 15, 16, 17]
rest_sum = [7, 8, 9, 10, 18, ...30]






"""