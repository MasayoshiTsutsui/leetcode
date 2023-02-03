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
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> dic;
        vector<vector<string> > ans;
        int idx = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs.at(i);
            sort(str.begin(), str.end());
            if (dic.find(str) != dic.end()) {
                ans.at(dic.at(str)).push_back(strs.at(i));
            }
            else {
                vector<string> newbox = {strs.at(i)};
                ans.push_back(newbox);
                dic.emplace(str, idx);
                idx++;
            }
        }
        return ans;
    }
};