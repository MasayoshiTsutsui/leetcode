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
    bool isCapable(vector<int>& weights, int midCapa) {
        int sum
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sumW = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sumW += weights.at(i);
        }

        int rightCapa = sumW;
        int leftCapa = 0;
        int ans = sumW;

        while (leftCapa <= rightCapa)
        {
            int midCapa = leftCapa + (rightCapa - leftCapa) / 2;
            int onShipW = 0;
            int passedDays = 1;
            for (int i = 0; i < weights.size(); i++)
            {
                if (weights.at(i) > midCapa)
                {
                    passedDays = INT_MAX;
                    break;
                }
                else if (onShipW + weights.at(i) <= midCapa)
                {
                    onShipW += weights.at(i);
                }
                else
                {
                    passedDays++;
                    onShipW = weights.at(i);
                }
            }
            if (passedDays <= days)
            {
                ans = midCapa;
                rightCapa = midCapa-1;
            }
            else
            {
                leftCapa = midCapa+1;
            }
        }
        return ans;
    }
};