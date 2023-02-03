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
        int left = 0;
        int right = nums.size() - 1;
        if (nums.at(left) < nums.at(right)) {
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (nums.at(mid) == target) {
                    return mid;
                }
                else if (nums.at(mid) < target) {
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
            if (nums.at(left) != target) {
                return -1;
            }
            return left;
        }
        else {
            if (nums.at(left) == target) {
                return left;
            }
            if (nums.at(right) == target) {
                return right;
            }
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums.at(left) < nums.at(mid)) {
                    if (nums.at(mid) == target) {
                        return mid;
                    }
                    else if (nums.at(left) < target && target < nums.at(mid)) {
                        right = mid;
                    }
                    else {
                        left = mid;
                    }
                }
                else {
                    if (nums.at(left) <= target || nums.at(mid) > target) {
                        right = mid;
                    }
                    else {
                        left = mid;
                    }
                }
            }
        }
        if (nums.at(left) != target) {
            return -1;
        }
        return left;
    }
};