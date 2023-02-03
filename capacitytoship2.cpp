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
    int shipWithinDays(vector<int>& weights, int days) {
        int maxw = -1;

        for (int i = 0; i < weights.size(); i++)
        {
            maxw = max(maxw, weights.at(i));
        }
        int left = 0;
        int right = maxw * weights.size();
        while (left < right) {
            int mid = (left + right) / 2;
            int loaded = 0;
            int daycnt = 0;

            bool uncapable = false;

            for (int i = 0; i < weights.size(); i++)
            {
                if (weights.at(i) > mid) {
                    uncapable = true;
                    break;
                }
                else if (loaded + weights.at(i) <= mid) {
                    loaded += weights.at(i);
                }
                else {
                    daycnt++;
                    loaded = weights.at(i);
                }
            }
            if (uncapable) {
                left = mid;
            }
            else if (daycnt + 1 <= days) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
};