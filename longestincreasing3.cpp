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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lenWithMe(nums.size(), 1);
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums.at(i) > nums.at(j) && lenWithMe.at(i) < lenWithMe.at(j) + 1)  {
                    lenWithMe.at(i) = lenWithMe.at(j) + 1;
                }
            }
            ans = max(ans, lenWithMe.at(i));
        }
        return ans;
    }
};