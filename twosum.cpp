class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        vector<pair<int, int>> num_and_indices(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            num_and_indices.at(i) = make_pair(nums.at(i), i);
        }
        
        sort(num_and_indices.begin(), num_and_indices.end());
        int leftidx = 0; int rightidx = nums.size()-1;
        for (int i = 0; i < nums.size(); i++)
        {
            pair<int, int> numind_left = num_and_indices.at(leftidx);
            pair<int, int> numind_right = num_and_indices.at(rightidx);
            int sum = numind_left.first + numind_right.first;
            if (sum == target) {
                ans.at(0) = numind_left.second;
                ans.at(1) = numind_right.second;
            }
            else if (sum > target) {
                rightidx--;
            }
            else {
                leftidx++;
            }
        }
        return ans;
    }
};