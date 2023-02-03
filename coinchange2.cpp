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
        vector<int> coinnumBy(amount+1, INT_MAX);
        coinnumBy.at(0) = 0;

        for (int i = 0; i < amount; i++)
        {
            if (coinnumBy.at(i) == INT_MAX) {
                continue;
            }
            for (int j = 0; j < coins.size(); j++)
            {
                int coin = coins.at(j);
                if (coin == INT_MAX || i+coin > amount) {
                    continue;
                }
                coinnumBy.at(i + coin) = min(coinnumBy.at(i + coin), coinnumBy.at(i) + 1);
            }

        }
        if (coinnumBy.at(amount) == INT_MAX) {
            return -1;
        }
        return coinnumBy.at(amount);
    }
};