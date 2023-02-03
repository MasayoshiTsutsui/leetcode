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
    int maxProfit(vector<int>& prices) {
        int maxProfByNow = 0;
        int minByNow = prices.at(0);
        for (int i = 1; i < prices.size(); i++)
        {
            maxProfByNow = max(maxProfByNow, prices.at(i) - minByNow);
            minByNow = min(minByNow, prices.at(i));
        }
        return maxProfByNow;
    }
};