from collections import deque 

LETTER_NUM = 26

class Solution:

    def removeDuplicateLetters(self, s: str) -> str:
        stk = deque()
        selected_chars = set()
        char_rest_cnts = [0 for _ in range(LETTER_NUM)]
        last_appeared_idx = [-1 for _ in range(LETTER_NUM)]

        for idx, c in enumerate(s):
            char_rest_cnts[ord(c) - ord("a")] += 1
            last_appeared_idx[ord(c) - ord("a")] = idx
        
        for c in s:
            if c in selected_chars:
                continue

            while len(stk) > 0 \
                    and ord(stk[-1]) > ord(c) \
                    and  last_appeared_idx[ord(stk[-1]) - ord("a")]:

                selected_chars.remove(stk[-1])
                a = stk.pop()

            stk.append(c)
            selected_chars.add(c)
            char_rest_cnts[ord(c) - ord("a")] -= 1
        
        ans = ""

        for c in stk:
            ans += c
        return ans
