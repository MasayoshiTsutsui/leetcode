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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinnumBy(amount+1, INT_MAX);
        coinnumBy.at(0) = 0;

        for (int i = 0; i < amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int coin = coins.at(j);
                if (coinnumBy.at(i) != INT_MAX && coin <= amount - i)
                {
                    coinnumBy.at(i + coin) = min(coinnumBy.at(i + coin), coinnumBy.at(i) + 1);
                }
            }
        }
        if (coinnumBy.at(amount) == INT_MAX)
        {
            return -1;
        }
        else
        {
            return coinnumBy.at(amount);
        }
    }
};