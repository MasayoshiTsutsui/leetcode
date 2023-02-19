
class Solution:
    def magicalString(self, n: int) -> int:
        if n <= 3:
            return 1
        magical = [1,2,2]
        next_num = 1

        for second_idx in range(2, n):
            magical.append(next_num)
            if len(magical) == n:
                break
            if magical[second_idx] == 2:
                magical.append(next_num)
            if len(magical) == n:
                break
            next_num = (1 if next_num == 2 else 2)

        return magical.count(1)

print(Solution().magicalString(8))

'''

122112
1221
'''