from typing import List

import heapq

DEBUG = 0

def dbg_print(s):
    if DEBUG:
        print(s)


class Solution:
        
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        class MatrixIdx:
            def __init__(self, i, j) -> None:
                self.i = i
                self.j = j
        
            def __lt__(self, other):
                return matrix[self.i][self.j] < matrix[other.i][other.j]

        p_que = []
        heapq.heapify(p_que)
        heapq.heappush(p_que, MatrixIdx(0, 0))

        while True:
            small_idxs = heapq.heappop(p_que)
            k -= 1
            small_i = small_idxs.i
            small_j = small_idxs.j
            dbg_print(f"k: {k}")
            dbg_print(f"matrix[small_i][small_j]: {matrix[small_i][small_j]}")

            if k == 0:
                return matrix[small_i][small_j]

            if small_j == 0 and small_i + 1 < len(matrix):
                heapq.heappush(p_que, MatrixIdx(small_i+1, small_j))
            if small_j + 1 < len(matrix[0]):
                heapq.heappush(p_que, MatrixIdx(small_i, small_j+1))


print(Solution().kthSmallest([[1,3,5],[6,7,12],[11,14,14]], 6))




"""

1 8 10
6 9 12
11 14 14


"""
        


