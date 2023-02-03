from typing import List
DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)



class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 0
        for i in range(n):
            distnorm_point = {}
            mid = points[i]
            for j in range(n):
                if i == j:
                    continue
                distnorm = (mid[0] - points[j][0]) ** 2 + (mid[1] - points[j][1]) ** 2
                if distnorm not in distnorm_point:
                    distnorm_point[distnorm] = 0
                distnorm_point[distnorm] += 1
            for edge_num in distnorm_point.values():
                if edge_num >= 2:
                    ans += edge_num * (edge_num - 1)
        return ans

a = [[0,0],[1,0],[2,0]]
b = [[1,1],[2,2],[3,3]]
c = [[1,1]]
print(Solution().numberOfBoomerangs(a))

