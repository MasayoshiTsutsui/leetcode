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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 99999999);
        dp.at(0) = 0;
        for (long long i = 0; i < dp.size(); i++)
        {
            for (long long c : coins)
            {
                if (i + c <= amount) {
                    dp.at(i + c) = min(dp.at(i) + 1, dp.at(i + c));
                }
            }
        }
        if (dp.at(amount) == 99999999) {
            return -1;
        }
        return dp.at(amount);
    }
};