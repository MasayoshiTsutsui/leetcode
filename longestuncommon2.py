from typing import List

class Solution:
    def issubsequence(self, base: str, comp: str) -> bool:
        if len(base) > len(comp):
            return False
        baseIdx = 0
        for c in comp:
            if base[baseIdx] == c:
                baseIdx += 1
                if baseIdx == len(base):
                    return True
        return False

    def findLUSlength(self, strs: List[str]) -> int:
        strs.sort(key=len, reverse=True)
        for i, s in enumerate(strs):
            if all(not self.issubsequence(s, t) for j, t in enumerate(strs) if i != j):
                return len(s)
        return -1

strs = ["aaa","aaa","aa"]
print(Solution().findLUSlength(strs))

"""
aaa, aaa, c -> c
aaa, aba, ab -> aaa
aaa, aba, aba -> aaa

aba, aba, ab, bc
if len is all same:
    return len(strs[i]) or -1
else:



"""

