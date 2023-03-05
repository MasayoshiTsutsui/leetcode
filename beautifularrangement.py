from functools import lru_cache
class Solution:
    @lru_cache(None)
    def dfs(self, bm: int, pos: int) -> int:
        if pos == 0:
            return 1

        count = 0
        for i in range(self.n):
            if not bm & (1 << i) and (pos % (i + 1) == 0 or (i + 1) % pos == 0):
                count += self.dfs(bm^1<<i, pos - 1)

        return count


    def countArrangement(self, n: int) -> int:
        self.n = n
        return self.dfs(0, n)



print(Solution().countArrangement(5))
