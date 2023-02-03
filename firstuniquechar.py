class Solution:
    def firstUniqChar(self, s: str) -> int:
        def char2int(c: str):
            return ord(c) - ord('a')

        char_cnt = [0] * 26

        for c in s:
            char_cnt[char2int(c)] += 1
        for i, c in enumerate(s):

            if char_cnt[char2int(c)] == 1:
                return i

        return -1
