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

    void dfsgen(vector<string>& ans, string par, int opened, int closed, int n) {
        if (opened == n && closed == n) {
            ans.push_back(par);
            return;
        }
        if (opened < n) {
            dfsgen(ans, par+'(', opened+1, closed, n);
        }
        if (closed < n && opened >= closed + 1) {
            dfsgen(ans, par+')', opened, closed+1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        int opened = 0;
        int closed = 0;
        vector<string> ans;
        dfsgen(ans, "", 0, 0, n);

        return ans;
    }
};