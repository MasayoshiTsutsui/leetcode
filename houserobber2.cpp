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
        int n = nums.size();
        if (n == 1) {
            return nums.at(0);
        }

        int maxWithMeFirst = 0;
        int maxWithoutMeFirst = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int maxWithMeTemp = maxWithMeFirst;

            maxWithMeFirst = maxWithoutMeFirst + nums.at(i);
            maxWithoutMeFirst = max(maxWithMeTemp, maxWithoutMeFirst);
        }

        int maxWithMeLast = 0;
        int maxWithoutMeLast = 0;

        for (int i = 1; i < n; i++)
        {
            int maxWithMeTemp = maxWithMeLast;
            maxWithMeLast = maxWithoutMeLast + nums.at(i);
            maxWithoutMeLast = max(maxWithMeTemp, maxWithoutMeLast);
        }
        int ans = max(max(maxWithMeFirst, maxWithoutMeFirst), max(maxWithMeLast, maxWithoutMeLast));
        return ans;
    }
};