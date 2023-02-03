
DEBUG = 0

def dbg_print(s):
    if DEBUG:
        print(s)

class Solution:

    def getMoneyAmount(self, n: int) -> int:
        cost_within = [[0] * (n+1) for _ in range(n + 1)]

        for hi in range(1, n+1):
            for lo in range(hi-1, 0, -1):
                cost_within[lo][hi] = \
                    min(x + max(cost_within[lo][x-1], cost_within[x+1][hi]) for x in range(lo, hi))
                dbg_print(f"cost_within[{lo}][{hi}]: {cost_within[lo][hi]}")
                if hi == 6 and lo == 1:
                    for x in range(lo, hi):
                        dbg_print(f"cost_within[{lo}][{x-1}]: {cost_within[lo][x-1]}")
                        dbg_print(f"cost_within[{x+1}][{hi}]: {cost_within[x+1][hi]}")
                        dbg_print("")
        
        return cost_within[1][n]

Solution().getMoneyAmount(6)