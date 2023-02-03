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
    int rob(vector<int>& nums) {
        int max1_without_me = 0;
        int max1_with_me = nums.at(0);
        int max2_without_me = 0;
        int max2_with_me = 0;

        for (int i = 1; i < nums.size() - 1; i++)
        {
            int n = nums.at(i);
            int tmp = max1_with_me;
            max1_with_me = max(max1_without_me + n, max1_with_me);
            max1_without_me = max(max1_without_me, tmp);
        }
        int max1 = max(max1_with_me, max1_without_me);

        for (int i = 1; i < nums.size(); i++)
        {
            int n = nums.at(i);
            int tmp = max2_with_me;
            max2_with_me = max(max2_without_me + n, max2_with_me);
            max2_without_me = max(max2_without_me, tmp);
        }
        int max2 = max(max2_with_me, max2_without_me);
        return max(max1, max2);
    }
};