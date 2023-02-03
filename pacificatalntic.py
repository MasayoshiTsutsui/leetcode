from typing import List
DEBUG = 0

def dbg_print(s):
    if DEBUG:
        print(s)



class Solution:
    def dfs(self, prev_x, prev_y, xy_incr, visited):
        x_incr = xy_incr[0]
        y_incr = xy_incr[1]

        x = prev_x + x_incr
        y = prev_y + y_incr


        if y < 0 or x < 0 or y >= self.m or x >= self.n or visited[y][x] or self.heights[y][x] < self.heights[prev_y][prev_x]:
            return
        dbg_print(f"x,y: {x,y}")

        visited[y][x] = True
        for dir in self.dirs:
            self.dfs(x, y, dir, visited)


    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.m = len(heights)
        self.n = len(heights[0])
        self.heights = heights
        self.visitedPac = [[False] * self.n for _ in range(self.m)]
        self.visitedAtl = [[False] * self.n for _ in range(self.m)]
        self.dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        ans = []

        for y in range(self.m):
            self.dfs(0, y, (0, 0), self.visitedPac)
            self.dfs(self.n-1, y, (0, 0), self.visitedAtl)
        for x in range(self.n):
            self.dfs(x, 0, (0, 0), self.visitedPac)
            self.dfs(x, self.m-1, (0, 0), self.visitedAtl)
        
        for y in range(self.m):
            for x in range(self.n):
                if self.visitedPac[y][x] and self.visitedAtl[y][x]:
                    ans.append([y, x])
        return ans

a = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
a = [[1]]
print(Solution().pacificAtlantic(a))