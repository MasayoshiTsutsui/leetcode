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
    void dfsPermute(vector<vector<int> >& ans, vector<int>& nums, int head) {
        if (head == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = head; i < nums.size(); i++)
        {
            swap(nums.at(head), nums.at(i));
            dfsPermute(ans, nums, head+1);
            swap(nums.at(head), nums.at(i));
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        dfsPermute(ans, nums, 0);
        return ans;
    }
};