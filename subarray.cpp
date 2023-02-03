#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_occur;
        int ans = 0;
        int sum = 0;
        sum_occur.emplace(0, 1);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums.at(i);
            auto founditr = sum_occur.find(sum-k);

            if (founditr != sum_occur.end()) {
                ans += founditr->second;
            }

            auto p = sum_occur.emplace(sum, 1);
            if (!p.second) {
                sum_occur.at(sum)++;
            }
        }
        return ans;
    }
};