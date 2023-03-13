class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        ans = ""
        for sep in range(0, len(s), 2 * k):
            base = s[sep:sep + 2 * k]
            ans += base[:k][::-1] + base[k:]
        return ans

s = "abcdefg"
print(Solution().reverseStr(s, 2))