import math


class Solution:

    def repeatedSubstringPattern(self, s: str) -> bool:

        for i in range(1, len(s) // 2 + 1):
            if len(s) % i != 0:
                continue
            sub = s[:i]

            if sub * (len(s) // i) == s:
                return True
        return False
b = "aba"
c = "abcabcabcabc"
d = "abacababacab"
print(Solution().repeatedSubstringPattern(d))




