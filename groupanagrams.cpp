#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        int newansidx = 0;


        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs.at(i);
            string sorted_s = string(s);
            sort(sorted_s.begin(), sorted_s.end());
            if (!map.contains(sorted_s)) {
                map.emplace(sorted_s, {});
            }
            map.at(sorted_s).push_back(s);
        }

        vector<vector<string>> ans;
        for (auto itr = map.begin(); itr != map.end(); itr++)
        {
            ans.push_back(itr->second);
        }
        
        return ans;
    }
};