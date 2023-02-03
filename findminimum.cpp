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
    int findMin(vector<int>& nums) {
        int leftnum = nums.at(0);
        int rightnum = nums.at(nums.size() - 1);
        
        int left = -1;
        int right = nums.size();

        while(left + 1 < right)
        {
            int mid = (left + right) / 2;
            int midnum = nums.at(mid);
            if (leftnum < rightnum)
            {
                return leftnum;
            }
            else if (leftnum > midnum)
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
        return rightnum;
    }
};