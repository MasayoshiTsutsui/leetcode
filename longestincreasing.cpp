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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> longestsubseq(n);
        
        for (int i = 0; i < n; i++)
        {
            int num = nums.at(i);
            longestsubseq.at(i) = 1;

            for (int j = 0; j < i; j++)
            {
                if (nums.at(j) < num)
                {
                    longestsubseq.at(i) = max(longestsubseq.at(j)+1, longestsubseq.at(i));
                }
            }
        }
        int maxlen = 0;

        for (int i = 0; i < n; i++)
        {
            maxlen = max(maxlen, longestsubseq.at(i));
        }
        return maxlen;
    }
};