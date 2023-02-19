from typing import List
import copy

DEBUG = 1

def dbg_print(s):
    if DEBUG:
        print(s)

class ZeroOne:
    def __init__(self, id: int, zeros: int, ones: int) -> None:
        self.id = id
        self.zeros = zeros
        self.ones = ones

    def __hash__(self) -> int:
        return hash(self.id)

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        zeroOneCnt = []

        for id, s in enumerate(strs):
            zeroOneCnt.append((s.count('0'), s.count('1')))

        dp = [[None] * (n + 1) for _ in range(m + 1)]

        for id, (zeros, ones) in enumerate(zeroOneCnt):
            if zeros <= m and ones <= n:
                if dp[zeros][ones] == None:
                    dp[zeros][ones] = []
                dp[zeros][ones].append([id])
                #dbg_print(f"dp[zeros][ones]: {dp[zeros][ones]}")

        for i in range(m + 1):
            for j in range(n + 1):
                dbg_print(f"dp: {dp}")
                components = dp[i][j]
                if components != None:
                    for c in components:
                        for id, (zeros, ones) in enumerate(zeroOneCnt):
                            if id in c:
                                continue
                            if i + zeros <= m and j + ones <= n:
                                if dp[i + zeros][j + ones] == None:
                                    dp[i + zeros][j + ones] = []
                                
                                next_c = copy.deepcopy(c)
                                next_c.append(id)
                                dp[i + zeros][j + ones].append(next_c)
        
        #dbg_print(f"dp[m][n]: {dp[m][n]}")
        if dp[m][n] == None:
            return 0
        
        pathlens = [len(a) for a in dp[m][n]]
        return max(pathlens)


strs = ["10","0001","111001","1","0"]
m = 3
n = 4
print(Solution().findMaxForm(strs, m, n))