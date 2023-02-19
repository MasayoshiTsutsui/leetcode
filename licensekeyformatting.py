class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace("-", "").upper()[::-1]
        return "-".join([s[i:i+k] for i in range(0, len(s), k)])[::-1]


s = "2-5g-3-J"
k = 2

print(Solution().licenseKeyFormatting(s, k))