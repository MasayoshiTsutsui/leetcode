from itertools import zip_longest
class Solution:

    def addStrings(self, num1: str, num2: str) -> str:
        large = num1 if len(num1) >= len(num2) else num2
        small = num2 if len(num1) >= len(num2) else num1
        large = large[::-1]
        small = small[::-1]

        carry_exists = 0
        reversed_ans = ""
        for d1, d2 in zip_longest(large, small):
            if not d2:
                sumd_ord_tmp = ord(d1) + carry_exists
            else:
                sumd_ord_tmp = ord(d1) + ord(d2) - ord('0') + carry_exists

            if sumd_ord_tmp > ord('9'):
                sumd_ord_tmp -= 10
                carry_exists = 1
            else:
                carry_exists = 0
            reversed_ans += chr(sumd_ord_tmp)
        
        if carry_exists:
            reversed_ans += '1'
        
        return reversed_ans[::-1]

n1 = "11"
n2 = '123'

print(Solution().addStrings(n1, n2))