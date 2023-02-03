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
    void dfs_swap(vector<vector<int>>& ans, vector<int>& nums, int head) {
        if (head == nums.size() - 1) {
            ans.push_back(vector<int>(nums));
            return
        }
        for (int i = 0; i < nums.size() - head; i++)
        {
            swap(nums.at(head), nums.at(head + i));
            dfs_swap(ans, nums, head + 1);
            swap(nums.at(head), nums.at(head + i));
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs_swap(ans, nums, 0);
        return ans;
    }
};