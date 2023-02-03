class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        maxPow3 = 3 ** 31
        
        if n > 0 and maxPow3 % n == 0:
            return True
        else:
            return False
