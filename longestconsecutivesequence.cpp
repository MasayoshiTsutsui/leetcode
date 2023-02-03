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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        if (nums.size() == 0) {
            return 0;
        }
        for (int num : nums)
        {
            hash.insert(num);
        }
        int ans = -1;

        for (int num : nums)
        {
            if (hash.find(num-1) == hash.end()) {
                int currentNum = num;
                int length = 1;
                while (hash.find(currentNum+1) != hash.end()) {
                    currentNum++;
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};