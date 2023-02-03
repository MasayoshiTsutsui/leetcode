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
    void dfs(vector<string>& ans, string digits, string letters,  int head) {
        if (head == digits.size()) {
            ans.push_back(letters);
            return;
        }
        char basechar;
        switch (digits.at(head))
        {
        case '7':
            basechar = 'p';
            for (int i = 0; i < 4; i++)
            {
                char c = basechar + i;
                dfs(ans, digits, letters+c, head+1);
            }
            break;
        case '8':
            basechar = 't';
            for (int i = 0; i < 3; i++)
            {
                char c = basechar + i;
                dfs(ans, digits, letters+c, head+1);
            }
            break;
        case '9':
            basechar = 'w';
            for (int i = 0; i < 4; i++)
            {
                char c = basechar + i;
                dfs(ans, digits, letters+c, head+1);
            }
            break;
        default:
            basechar = (digits.at(head) - '2') * 3 + 'a';
            for (int i = 0; i < 3; i++)
            {
                char c = basechar + i;
                dfs(ans, digits, letters+c, head+1);
            }
            break;
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") {
            return ans;
        }
        dfs(ans, digits, "", 0);
        return ans;
    }
};