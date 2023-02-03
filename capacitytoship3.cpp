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
        int left = 0;
        int right = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            right += weights.at(i);
        }
        while (left < right) {
            int mid = (left + right) / 2;
            int loadable = mid;
            int shipCnt = 1;
            bool flag = false;
            for (int i = 0; i < weights.size(); i++)
            {
                int w = weights.at(i);
                if (mid < w) {
                    flag = true;
                    break;
                }
                if (loadable < w) {
                    shipCnt++;
                    loadable = mid - w;
                }
                else {
                    loadable -= w;
                }
            }
            if (flag) {
                left = mid + 1;
            }
            else if (shipCnt > days) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
};