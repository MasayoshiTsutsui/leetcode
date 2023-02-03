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
        int buyprice = -1;
        int maxProf = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == prices.size() - 1)
            {
                if (buyprice != -1)
                {
                    maxProf += prices.at(i) - buyprice;
                }
            }
            else if (buyprice != -1 && prices.at(i) > prices.at(i+1))
            {
                maxProf += prices.at(i) - buyprice;
                buyprice = -1;
            }
            else if (buyprice == -1 && prices.at(i) < prices.at(i+1))
            {
                buyprice = prices.at(i);
            }
        }
        return maxProf;
    }
};