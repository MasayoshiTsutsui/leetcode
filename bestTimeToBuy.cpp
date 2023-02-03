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
    int maxProfit(vector<int>& prices) {
        int buy = -prices.at(0); int sell = 0; int rest = 0; int keep = -prices.at(0);
        int prev_buy = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int p = prices.at(i);
            prev_buy = buy;
            buy = rest - p;
            rest = max(sell, rest);
            sell = max(prev_buy + p, keep + p);
            keep = max(prev_buy, keep);
        }
        return max(sell, rest);
    }
};