
DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stk = []
        charCnt = {}

        for c in s:
            if c not in charCnt:
                charCnt[c] = 0
            charCnt[c] += 1
        visited = set()

        for c in s:
            if c in visited:
                charCnt[c] -= 1
                continue
            while len(stk) > 0 and stk[-1] > c and charCnt[stk[-1]] > 0:
                visited.remove(stk.pop())
            stk.append(c)
            visited.add(c)
            charCnt[c] -= 1

        return "".join(stk)



s = "bbcaac"
print(Solution().removeDuplicateLetters(s))



"""
bcabc
bab
bca -> abc

cbacdcbc
cba -> bacd -> bacd -> acdb
"""