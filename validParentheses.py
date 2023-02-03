import sys

class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        brMap = {')': '(', '}': '{' , ']': '['}
        for c in s:
            if c in ['(', '{', '[']:
                stk.append(c)
            else:
                if len(stk) != 0 and brMap[c] == stk[-1]:
                    stk.pop()
                else:
                    return False
        if len(stk) == 0:
            return True
        else:
            return False


                    

