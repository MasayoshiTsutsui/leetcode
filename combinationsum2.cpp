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
    bool dfs(vector<vector<int> >& ans, vector<int>& candidates, int target, vector<int>& combi, int sum, int head) {
        if (sum == target) {
            ans.push_back(combi);
            return true;
        }
        if (sum > target) {
            return true;
        }

        for (int i = head; i < candidates.size(); i++)
        {
            int cand = candidates.at(i);
            combi.push_back(cand);
            bool flow = dfs(ans, candidates, target, combi, sum + cand, i);
            combi.pop_back();
            if (flow) {
                break;
            }
        }
        
        return false;
    }

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        sort(candidates.begin(), candidates.end());
        vector<int> combi;
        dfs(ans, candidates, target, combi, 0, 0);
        return ans;
    }
};