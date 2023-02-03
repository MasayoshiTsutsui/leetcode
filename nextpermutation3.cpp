#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


//...1,2,3
//-> ....1,3,2

//..1,3,2
//-> ...2,1,3

//// search ascending sequential 2 numbers from the tail of the vector
//// we should swap first of the 2 numbers with minimum val larger than the first of 2 among the searched numbers
//// sort the latter

//3,2,1
//-



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int next_pivot = 999;
        int next_pivot_idx = n;
        int pivot = 999;
        int pivot_idx = n;
        if (n == 1) {
            return;
        }
        for (int i = n - 1; i >= 1; i--)
        {
            if (nums.at(i - 1) < nums.at(i) || i == 1) {
                pivot = nums.at(i - 1);
                pivot_idx = i - 1;
                break;
            }
        }

        for (int i = pivot_idx; i < n; i++) {
            if (pivot < nums.at(i) && next_pivot > nums.at(i)) {
                next_pivot = nums.at(i);
                next_pivot_idx = i;
            }
            if (i == n - 1 && next_pivot == 999) {
                next_pivot = nums.at(n - 1);
                next_pivot_idx = n - 1;
            }
        }

        swap(nums.at(pivot_idx), nums.at(next_pivot_idx));
        sort(nums.begin() + pivot_idx + 1, nums.end());
    }
};