from typing import List

class Solution:
    def binsearch(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        if nums[right] < target:
            return len(nums)

        while left < right:
            mid = (left + right) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1

        return left


    def remove_duplicates(self, nums: List[int]) -> List[int]:
        new_tail = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[new_tail] = nums[i]
                new_tail += 1
        return nums[:new_tail]

    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        self.remove_duplicates(houses)

        ans = -1

        for i in range(len(houses)):
            idxToInsert_left = self.binsearch(heaters, houses[i])
            min_applicants = [9999999999]
            if idxToInsert_left < len(heaters):
                min_applicants.append(heaters[idxToInsert_left] - houses[i])
            if idxToInsert_left - 1 >= 0:
                min_applicants.append(houses[i] - heaters[idxToInsert_left - 1])
            ans = max(ans, min(min_applicants))
            
            
        return ans

houses = [1,5]
heaters =[2]
print(Solution().findRadius(houses, heaters))


