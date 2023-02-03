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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numhash;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            numhash.insert(nums.at(i));
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (numhash.find(nums.at(i)-1) == numhash.end()) {
                int currentMax = 0;
                int currentNum = nums.at(i);
                while (numhash.find(currentNum) != numhash.end()) {
                    currentMax++;
                    currentNum++;
                }
                ans = max(currentMax, ans);
            }
        }
        return ans;
    }
};