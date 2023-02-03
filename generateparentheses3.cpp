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
    void dfs(int open_cnt, int close_cnt, string parenthes, const int n, vector<string>& ans) {
        if (open_cnt < close_cnt) {
            return;
        }
        if (open_cnt == n && close_cnt == n) {
            ans.push_back(parenthes);
            return;
        }

        if (open_cnt < n) {
            dfs(open_cnt + 1, close_cnt, parenthes + '(', n, ans);
        }
        if (close_cnt < n) {
            dfs(open_cnt, close_cnt + 1, parenthes + ')', n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0, 0, "", n, ans);
        return ans;
    }
};