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
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums.at(i);
            int max_len = 1;
            for (int j = 0; j < i; j++)
            {
                if (n > nums.at(j)) {
                    max_len = max(max_len, dp.at(j)+1);
                }
            }
            dp.at(i) = max_len;
            ans = max(ans, max_len);
        }
        return dp.at(nums.size()-1);
    }
};