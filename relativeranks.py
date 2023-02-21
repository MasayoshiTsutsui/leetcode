from typing import List
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        scoreIds = [i for i in range(len(score))]
        scoreIds.sort(key=lambda x: score[x], reverse=True)
        
        if len(score) > 0:
            score[scoreIds[0]] = "Gold Medal"
        if len(score) > 1:
            score[scoreIds[1]] = "Silver Medal"
        if len(score) > 2:
            score[scoreIds[2]] = "Bronze Medal"

        for i in range(3, len(score)):
            score[scoreIds[i]] = str(i + 1)
        return score

scores = [10,3,8,9,4]
print(Solution().findRelativeRanks(scores))