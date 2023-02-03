
class Solution:

    def removeKdigits(self, num: str, k: int) -> str:
        stk = []
        
        for n in num:
            while stk and k and stk[-1] > n:
                stk.pop()
                k -= 1
            if n != '0':
                stk.append(n)
        
        if k > 0:
            stk = stk[:-k]
        return ''.join(stk) or '0'



print(Solution().removeKdigits("10", 2))
