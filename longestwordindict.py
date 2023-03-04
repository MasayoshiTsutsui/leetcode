from typing import List

class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        ans = ""
        for word in dictionary:
            w_idx = 0
            for c in s:
                if w_idx == len(word):
                    break
                if word[w_idx] == c:
                    w_idx += 1
            if w_idx == len(word):
                if len(ans) == len(word):
                    ans = min(ans, word)
                else:
                    ans = max(ans, word, key=len)
        return ans

s= "abpcplea"
dic = ["a","b","c"]
print(Solution().findLongestWord(s, dic))

