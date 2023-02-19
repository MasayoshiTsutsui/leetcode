#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) == target) {
                return mid;
            }
            if (nums.at(mid) > target) {
                right = mid;
            }
            if (nums.at(mid) < target) {
                left = mid + 1;
            }
        }
    }
};