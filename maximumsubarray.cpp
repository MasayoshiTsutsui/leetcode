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
    int maxSubArray(vector<int>& nums) {
        int ans = nums.at(0);
        int curmax = nums.at(0);
        for (int i = 1; i < nums.size(); i++)
        {
            if (curmax + nums.at(i) < nums.at(i))
            {
                curmax = nums.at(i);
            }
            else
            {
                curmax = curmax + nums.at(i);
            }
            ans = max(ans, curmax);
        }
        return ans;
    }
};