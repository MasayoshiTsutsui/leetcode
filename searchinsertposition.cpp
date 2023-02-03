#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = -1;
        int right = nums.size();

        while(left + 1 < right)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) == target)
            {
                return mid;
            }
            else if (nums.at(mid) > target)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return right;
    }
};