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
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int head, int target, int sum, vector<int>& one_ans) {
        if (sum == target) {
            ans.push_back(vector<int>(one_ans));
            return;
        }
        else if (sum > target) {
            return;
        }

        for (int i = 0; i < candidates.size() - head; i++)
        {
            int num = candidates.at(head + i);
            one_ans.push_back(num);
            dfs(ans, candidates, head + i, target, sum + num, one_ans);
            one_ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> one_ans;
        dfs(ans, candidates, 0, target, 0, one_ans);
        return ans;
    }
};