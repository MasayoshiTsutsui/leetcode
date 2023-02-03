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
    void moveZeroes(vector<int>& nums) {
        int head = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.at(i) != 0) {
                nums.at(head) = nums.at(i);
                head++;
            }
        }
        for (int i = head; i < nums.size(); i++)
        {
            nums.at(i) = 0;
        }

        return;
    }
};