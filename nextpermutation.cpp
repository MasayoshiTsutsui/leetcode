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
    void nextPermutation(vector<int>& nums) {
        int last_ascend = -1;
        int next_pivot = -1;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums.at(i) < nums.at(i+1)) {
                last_ascend = i;
                next_pivot = i+1;
            }
            else if (last_ascend >= 0 && nums.at(last_ascend) < nums.at(i+1)) {
                if (nums.at(next_pivot) > nums.at(i+1)) {
                    next_pivot = i+1;
                }
            }
        }

        if (last_ascend == -1) {
            sort(nums.begin(), nums.end());
        }
        else {
            swap(nums.at(last_ascend), nums.at(next_pivot));
            sort(nums.begin() + last_ascend+1, nums.end());
        }
    }
};



1,2,3,4 - 1,2,4,3
2,3,1,4 - 2,3,4,1
3,2,4,1 - 