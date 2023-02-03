import numpy as np
class Solution:
    def frequencySort(self, s: str) -> str:
        letter_cnt = {}
        for c in s:
            if c not in letter_cnt:
                letter_cnt[c] = 0
            letter_cnt[c] += 1
        cnts = list(letter_cnt.values())
        letters = list(letter_cnt.keys())

        sorted_idxs = np.argsort(cnts)[::-1]

        ans = ''.join([letters[idx] * cnts[idx] for idx in sorted_idxs])
        return ans
s = "tree"
Solution().frequencySort(s)

