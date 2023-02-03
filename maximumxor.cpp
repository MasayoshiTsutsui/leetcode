#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        uint32_t mask = 0;
        uint32_t ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            mask |= 1 << i;
            unordered_set<uint32_t> prefixes;
            for (int i = 0; i < nums.size(); i++)
            {
                prefixes.insert(nums.at(i) & mask);
            }

            uint32_t ans_expected = ans | (1 << i);

            for (auto itr = prefixes.begin(); itr != prefixes.end(); itr++)
            {
                uint32_t prefix = *itr;
                if (prefixes.find(ans_expected ^ prefix) != prefixes.end()) {
                    ans = ans_expected;
                    break;
                }
            }
        }
        return ans;
    }
};
int main() {
    int num[] = {3,10,5,25,2,8};
    vector<int> nums(num, end(num));
    cout << Solution().findMaximumXOR(nums) << endl;
    return 0;
}
