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
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int ansTemp = 0;
        int left = 0;
        int right = 0;
        int sum = 0;

        while (right <= nums.size()) {
            if (sum >= target) {
                ans = min(ans, ansTemp);
                sum -= nums.at(left);
                left++;
                ansTemp--;
            }
            else {
                if (right == nums.size()) {
                    break;
                }
                sum += nums.at(right);
                right++;
                ansTemp++;
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
        else {
            return ans;
        }
    }
};