from typing import List, Tuple

DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)



class Solution:

    def dfs(self,
            matrix: List[List[int]],
            maxpath_from: List[List[int]],
            cur: Tuple[int, int],
            prev_num: int,
            depth: int) -> int:

        cur_i = cur[0]
        cur_j = cur[1]
        if not 0 <= cur_i < len(matrix) \
            or not 0 <= cur_j < len(matrix[0]) \
            or  matrix[cur_i][cur_j] <= prev_num:
            return 0
        cur_num = matrix[cur_i][cur_j]

        
        if maxpath_from[cur_i][cur_j] != -1:
            return maxpath_from[cur_i][cur_j]

        bottom = self.dfs(matrix, maxpath_from, (cur_i + 1, cur_j), cur_num, depth + 1)
        top = self.dfs(matrix, maxpath_from, (cur_i - 1, cur_j), cur_num, depth + 1)
        right = self.dfs(matrix, maxpath_from, (cur_i, cur_j + 1), cur_num, depth + 1)
        left = self.dfs(matrix, maxpath_from, (cur_i, cur_j - 1), cur_num, depth + 1)

        maxpath_from[cur_i][cur_j] = max(left, right, top, bottom) + 1

        return maxpath_from[cur_i][cur_j]

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        maxpath_from = [[-1] * n for _ in range(m)]
        ans = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                maxpath = self.dfs(matrix, maxpath_from, (i, j), -1, 0)
                ans = max(ans, maxpath)
        return ans


