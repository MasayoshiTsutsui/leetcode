from typing import List

class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        sell_dp = [0] * n
        buy_dp = [0] * n
        cooldown_dp = [0] * n

        buy_dp[0] = -prices[0]

        for i in range(1, n):
            sell_dp[i] = max(prices[i] + buy_dp[i-1], sell_dp[i])
            buy_dp[i] = max(buy_dp[i-1], cooldown_dp[i-1] - prices[i])
            cooldown_dp[i] = max(cooldown_dp[i-1], sell_dp[i-1])
        
        return max(sell_dp[n-1], cooldown_dp[n-1])