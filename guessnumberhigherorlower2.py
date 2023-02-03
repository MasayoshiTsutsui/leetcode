class Solution:
    def getMoneyAmount(self, n: int) -> int:
        cost_within = [[0] * (n + 1) for _ in range(n + 1)]

        for lo in range(n, 0, -1):
            for hi in range(lo + 1, n + 1):
                cost_within[lo][hi] = \
                    min(x + max(cost_within[lo][x-1], cost_within[x+1][hi]) for x in range(lo, hi))
        
        return cost_within[1][n]
        
