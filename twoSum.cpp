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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> cmpl_idx;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums.at(i);
            int cmpl = target - num;
            if (cmpl_idx.find(num) != cmpl_idx.end())
            {
                ans.push_back(cmpl_idx.at(num));
                ans.push_back(i);
            }
            cmpl_idx.emplace(cmpl, i);
        }
        return ans;
    }
};