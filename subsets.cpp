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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int maxbm = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            maxbm *= 2;
        }
        maxbm--;

        for (int bm = 0; bm <= maxbm; bm++)
        {
            vector<int> subset;
            for (int i = 0; i < nums.size(); i++)
            {
                if (bm >> i == 1) {
                    subset.push_back(nums.at(i));
                }
            }
            ans.push_back(subset);
        }

        return ans;
    }
};