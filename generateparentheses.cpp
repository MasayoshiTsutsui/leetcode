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
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > pars(n+1);
        pars.at(0).push_back("");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < pars.at(i-1).size(); j++)
            {
                string p = "(" + pars.at(i-1).at(j) + ")";
                pars.at(i).push_back(p);
            }

            for (int j = 1; j <= i-1; j++)
            {
                for (int l = 0; l < pars.at(j-1).size(); l++)
                {
                    for (int r = 0; r < pars.at(i-j-1).size(); r++)
                    {
                        string p = "(" + pars.at(j-1).at(l) + ")" + "(" + pars.at(i-j-1).at(r) + ")";
                        pars.at(i).push_back(p);
                    }
                }
            }
        }
        return pars.at(n);
    }
};

class Solution {
public:
    void dfs(vector<string>& ans, int openable, int closable, string s) {
        if (openable == 0 && closable == 0) {
            ans.push_back(s);
            return;
        }
        if (openable > 0) {
            dfs(ans, openable-1, closable+1, s+"(");
        }
        if (closable > 0) {
            dfs(ans, openable, closable-1, s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, n, 0, "");
        return ans;
    }
};