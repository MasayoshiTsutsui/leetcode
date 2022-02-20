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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        unordered_set<int> ansset;
        vector<int> ans;

        for (int num1 : nums1)
        {
            set.insert(num1);
        }

        for (int num2 : nums2)
        {
            if (set.find(num2) != set.end()) {
                ansset.insert(num2);
            }
        }

        for (int a : ansset)
        {
            ans.push_back(a);
        }
        return ans;
    }
};