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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums.at(i);
            int left = -1;
            int right = sub.size();
            bool foundflag = false;

            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (sub.at(mid) == num) {
                    foundflag = true;
                    break;
                }
                if (sub.at(mid) > num) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
            if (foundflag) {
                continue;
            }
            if (left + 1 == sub.size()) {
                sub.push_back(num);
            }
            else {
                sub.at(left+1) = num;
            }
        }
        return sub.size();
    }
};