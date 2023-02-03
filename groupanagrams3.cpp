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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (size_t i = 0; i < strs.size(); i++)
        {
            string sorted_str = strs.at(i);
            sort(sorted_str.begin(), sorted_str.end());
            if (map.find(sorted_str) == map.end())
            {
                map.emplace(sorted_str, vector<string>());
            }
            map.at(move(sorted_str)).push_back(move(strs.at(i)));
        }

        vector<vector<string>> ans;

        for (auto itr = map.begin(); itr != map.end(); itr++)
        {
            ans.push_back(move(itr->second));
        }

        return ans;
    }
};