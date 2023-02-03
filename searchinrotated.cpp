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
    int search(vector<int>& nums, int target) {
        int left = -1;
        int right = nums.size();
        int leftnum = nums.at(0);
        int rightnum = nums.at(nums.size()-1);

        while (left + 1 < right)
        {
            int mid = (left + right) / 2;
            int midnum = nums.at(mid);
            if (leftnum <= midnum)
            {
                if (target >= leftnum && target < midnum)
                {
                    right = mid;
                    rightnum = midnum;
                }
                else
                {
                    left = mid;
                    leftnum = midnum;
                }
            }
            else
            {
                if (target >= leftnum || target < midnum)
                {
                    right = mid;
                    rightnum = midnum;
                }
                else
                {
                    left = mid;
                    leftnum = midnum;
                }
            }
        }
        if (leftnum == target)
        {
            if (left == -1)

            return left;
        }
        else
        {
            return -1;
        }
    }
};