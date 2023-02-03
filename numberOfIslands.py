
from collections import deque
import queue
class Solution:
    def dfs(self, grid, i, j):
        if i >= 0 and i < self.m and j >= 0 and j < self.n and grid[i][j] == "1":
            grid[i][j] = "2"
            self.dfs(grid, i-1, j)
            self.dfs(grid, i+1, j)
            self.dfs(grid, i, j-1)
            self.dfs(grid, i, j+1)
        else:
            return

    def numIslands(self, grid: List[List[str]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])
        ans = 0
        que = queue.Queue()
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == "1":
                    ans += 1
                    grid[i][j] = "2"
                    que.put((i-1, j))
                    que.put((i+1, j))
                    que.put((i, j-1))
                    que.put((i, j+1))
                    while que.qsize() > 0:
                        y, x = que.get()
                        if 0 <= y < self.m and 0 <= x < self.n and grid[y][x] == "1":
                            grid[y][x] = "2"
                            que.put((y-1, x))
                            que.put((y+1, x))
                            que.put((y, x-1))
                            que.put((y, x+1))
        return ans
