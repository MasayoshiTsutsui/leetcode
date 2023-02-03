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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) {
            return ans;
        }
        int s = nums.at(0);
        int recent = nums.at(0);
        for (int i = 1; i < nums.size(); i++)
        {
            if (recent + 1 == nums.at(i)) {
                recent = nums.at(i);
            }
            else {
                if (s == recent) {
                    ans.push_back(to_string(s));
                }
                else {
                    ans.push_back(to_string(s) + "->" + to_string(recent));
                }
                s = nums.at(i);
                recent = nums.at(i);
            }
        }
        if (s == recent) {
            ans.push_back(to_string(s));
        }
        else {
            ans.push_back(to_string(s) + "->" + to_string(recent));
        }
        return ans;
    }
};