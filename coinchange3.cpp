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
private:
    int ans = 9999999;
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 999999);
        dp.at(0) = 0;
        
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int coin = coins.at(j);
                if (i - coin >= 0 && dp.at(i-coin) != 999999) {
                    dp.at(i) = min(dp.at(i), dp.at(i-coin) + 1);
                }
            }
        }
        if (dp.at(amount) == 999999) {
            return -1;
        }
        else {
            return dp.at(amount);
        }
    }
};