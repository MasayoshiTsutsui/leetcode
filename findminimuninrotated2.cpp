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
    int findMin(vector<int>& nums) {
        if (nums.at(0) < nums.at(nums.size()-1)) {
            return nums.at(0);
        }
        if (nums.size() == 1) {
            return nums.at(0);
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums.at(mid) > nums.at(left)) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return nums.at(left+1);
    }
};