class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1

        if n == 1:
            return 10

        prev_uniques = 9

        ans = 10

        for i in range(2, n + 1):
            ans += prev_uniques * (11 - i)
            prev_uniques *= (10 - i)
        return ans




"""
n = 0:

n = 1:
    unique: 0,1,2,3...9
    
n = 2:
    unique: 12, 13, 14, 

    11,22,33...,99

n = 3:
    112, 113, 114..., 119, 
    121, 131, 141..., 191




"""

