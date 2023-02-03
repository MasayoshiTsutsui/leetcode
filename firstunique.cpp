#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> c_idx;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s.at(i);
            auto p = c_idx.emplace(c, i);
            if (!p.second) {
                c_idx.at(c) = -1;
            }
        }
        int ans = -1;
        for (auto itr = c_idx.begin(); itr != c_idx.end(); itr++)
        {
            if (itr->second != -1) {
                if (ans == -1) {
                    ans = itr->second;
                }
                else {
                    ans = min(itr->second, ans);
                }
            }
        }
        return ans;
    }
};