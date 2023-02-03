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
    void nextPermutation(vector<int>& nums) {
        int lastacendIdx = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums.at(i) <= nums.at(i+1)) {
                lastacendIdx = i;
            }
        }
        if (lastacendIdx == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int nextmin = 9999;
        int nextminIdx = -1;
        for (int i = lastacendIdx; i < nums.size(); i++)
        {
            if (nums.at(lastacendIdx) <= nums.at(i)) {
                if (nums.at(i) < nextmin) {
                    nextmin = nums.at(i);
                    nextminIdx = i;
                }
                
            }
        }

        swap(nums.at(lastacendIdx), nums.at(nextminIdx));
        sort(nums.begin() + lastacendIdx + 1, nums.end());
    }
};