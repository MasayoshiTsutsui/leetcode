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
    void dfspermute(vector<vector<int> > &anslist, vector<int>& ans, vector<int>& nums, int head) {

        if (head == nums.size()) {
            anslist.push_back(ans);
            return;
        }
        
        for (int i = head; i < nums.size(); i++)
        {
            swap(nums.at(head), nums.at(i));
            ans.push_back(nums.at(head));
            dfspermute(anslist, ans, nums, head+1);
            swap(nums.at(head), nums.at(i));
            ans.pop_back();
        }
        
    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > anslist;
        vector<int> ans;
        dfspermute(anslist, ans, nums, 0);
        return anslist;
    }
};