
DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)

class Solution:
    def findMaximumXOR(self, nums):
        ans, mask = 0, 0
        for i in range(31, -1, -1):
            mask |= 1<<i
            found = set([num & mask for num in nums])
            dbg_print(f"found: {found}")
                
            start = ans | 1<<i
            dbg_print(f"start: {start}")
            for pref in found:
                dbg_print(f"pref: {pref}")
                if start^pref in found:
                    ans = start
                    break
         
        return ans


print(Solution().findMaximumXOR([1,3,5,7]))