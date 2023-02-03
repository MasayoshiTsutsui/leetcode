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
    int rob(vector<int>& nums) {
        int maxSumWithMe = 0;
        int maxSumWithoutMe = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int maxSumWithMeTemp = maxSumWithMe;
            maxSumWithMe = maxSumWithoutMe + nums.at(i);
            maxSumWithoutMe = max(maxSumWithMeTemp, maxSumWithoutMe);
        }
        return max(maxSumWithMe, maxSumWithoutMe);
    }
};