#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int> > cnts(nums.size());
        vector<int> ans(k);
        for (int i = 0; i < nums.size(); i++)
        {
            cnts.at(i) = make_pair(0, i);
        }
    

        for (int num : nums)
        {
            cnts.at();
        }

        priority_queue<pair<int, int> > que(cnts.begin(), cnts.end());

        for (int i = 0; i < k; i++)
        {
            ans.at(i) = que.top();
        }
        
    


        





        
    }
};