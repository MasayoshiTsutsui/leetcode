#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> str_and_idx;
        vector<vector<string>> ans;
        int newansidx = 0;


        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs.at(i);
            sort(s.begin(), s.end());
            auto ret = str_and_idx.emplace(s, newansidx);
            if (ret.second) {
                vector<string> newgroup = {strs.at(i)};
                ans.push_back(newgroup);
                newansidx++;
            }
            else {
                int groupidx = str_and_idx.at(s);
                ans.at(groupidx).push_back(strs.at(i));
            }
        }
        return ans;
    }
};