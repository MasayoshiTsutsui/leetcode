
from typing import List
class Person:
    def __init__(self, h_k:List[int]) -> None:
        self.h = h_k[0]
        self.k = h_k[1]
        self.rest_k = self.k
    
    def __lt__(self, other) -> bool:
        if self.rest_k == other.rest_k:
            return self.h < other.h
        return self.rest_k < other.rest_k

    def __le__(self, other) -> bool:
        if self.rest_k == other.rest_k:
            return self.h <= other.h
        return self.rest_k <= other.rest_k
    
    def __gt__(self, other) -> bool:
        if self.rest_k == other.rest_k:
            return self.h > other.h
        return self.rest_k > other.rest_k

    def __ge__(self, other) -> bool:
        if self.rest_k == other.rest_k:
            return self.h >= other.h
        return self.rest_k >= other.rest_k

class Solution:

    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        ans = []
        peoples = []

        for p in people:
            peoples.append(Person(p))


        for _ in range(len(peoples)):
            front = min(peoples)
            ans.append((front.h,front.k))
            front.rest_k = 99999999
            for people in peoples:
                if front.h >= people.h:
                    people.rest_k -= 1
        return ans

#a = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
a = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
print(Solution().reconstructQueue(a))