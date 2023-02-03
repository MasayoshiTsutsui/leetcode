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
    int search(vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums.at(left) == target) {
                return left;
            }
            else if (nums.at(left) < target) {
                if (nums.at(mid) == target) {
                    return mid;
                }
                else if (nums.at(mid) > target) {
                    right = mid - 1;
                }
                else {
                    if (nums.at(left) == nums.at(mid)) {
                        left = mid + 1;
                    }
                    else if (nums.at(left) < nums.at(mid)) {
                        left = mid + 1;
                    }
                    else if (nums.at(left) > nums.at(mid)) {
                        right = mid - 1;
                    }
                }
            }
            else if (nums.at(left) > target) {
                if (nums.at(mid) == target) {
                    return mid;
                }
                else if (nums.at(mid) > target) {
                    if (nums.at(left) == nums.at(mid)) {
                        left = mid + 1;
                    }
                    else if (nums.at(left) < nums.at(mid)) {
                        left = mid + 1;
                    }
                    else if (nums.at(left) > nums.at(mid)) {
                        right = mid - 1;
                    }
                }
                else if (nums.at(mid) < target) {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};