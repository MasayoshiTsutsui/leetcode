from typing import List

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        perimters = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    neighbor_waters = 0
                    if i - 1 < 0 or grid[i-1][j] == 0:
                        neighbor_waters += 1
                    if i + 1 >= m or grid[i+1][j] == 0:
                        neighbor_waters += 1
                    if j - 1 < 0 or grid[i][j-1] == 0:
                        neighbor_waters += 1
                    if j + 1 >= n or grid[i][j+1] == 0:
                        neighbor_waters += 1
                    perimters += neighbor_waters
        
        return perimters




grid = [[1, 0]]
print(Solution().islandPerimeter(grid))
