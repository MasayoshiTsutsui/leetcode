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
        int ans1 = 0;
        int ans2 = 0;

        int maxwithLast = 0;
        int maxwithoutLast = 0;
        if(nums.size() == 1) {
            return nums.at(0);
        }

        for (int i = 1; i < nums.size(); i++)
        {
            int maxwithLastTemp = maxwithLast;
            maxwithLast = maxwithoutLast + nums.at(i);
            maxwithoutLast = max(maxwithLastTemp, maxwithoutLast);
        }
        ans1 = max(maxwithLast, maxwithoutLast);

        maxwithLast = 0;
        maxwithoutLast = 0;

        for (int i = 0; i < nums.size()-1; i++)
        {
            int maxwithLastTemp = maxwithLast;
            maxwithLast = maxwithoutLast + nums.at(i);
            maxwithoutLast = max(maxwithLastTemp, maxwithoutLast);
        }
        ans2 = max(maxwithLast, maxwithoutLast);
        return max(ans1, ans2);
    }
};