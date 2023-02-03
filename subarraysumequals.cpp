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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sequential_sums;
        sequential_sums.insert(std::pair<int,int>{0,1});
        int ans = 0;
        int accum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums.at(i);
            accum += n;
            if (sequential_sums.find(accum - k) != sequential_sums.end()) {
                ans += sequential_sums.at(accum - k);
            }

            if (sequential_sums.find(accum) != sequential_sums.end()) {
                sequential_sums.at(accum)++;
            }
            else {
                sequential_sums.insert(std::pair<int,int>{accum,1});
            }
        }
        return ans;
    }
};