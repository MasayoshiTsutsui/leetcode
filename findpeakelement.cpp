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
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.at(0) > nums.at(1)) {
            return 0;
        }
        if (nums.at(n-1) > nums.at(n-2)) {
            return n-1;
        }
        int left = 1; int right = n-2;

        while(left < right) {
            int middle = (left + right) / 2;
            if (nums.at(middle-1) < nums.at(middle) && nums.at(middle) > nums.at(middle+1)) {
                return middle;
            }

            if (nums.at(left) < nums.at(middle) && nums.at(middle) > nums.at(right)) {
                if (nums.at(middle-1) > nums.at(middle) && nums.at(middle) < nums.at(middle+1)) {
                    left = middle + 1;
                }
                else if (nums.at(middle-1) <= nums.at(middle) && nums.at(middle) <= nums.at(middle+1)) {
                    left = middle + 1;
                }
                else if (nums.at(middle-1) >= nums.at(middle) && nums.at(middle) >= nums.at(middle+1)) {
                    right = middle;
                }
            }
            else if (nums.at(left) > nums.at(middle) && nums.at(middle) < nums.at(right)) {
                left = middle + 1;
            }
            else if (nums.at(left) <= nums.at(middle) && nums.at(middle) <= nums.at(right)) {
                left = middle + 1;
            }
            else if (nums.at(left) >= nums.at(middle) && nums.at(middle) >= nums.at(right)) {
                right = middle;
            }
        }
        return left;
    }
};