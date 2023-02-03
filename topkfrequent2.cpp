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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            auto p = hash.emplace(nums.at(i), 1);
            if (!p.second) {
                hash.at(nums.at(i)) = hash.at(nums.at(i)) + 1;
            }
        }
        auto comp = [&hash](int num1, int num2) {
            return hash.at(num1) < hash.at(num2);
        };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for (auto i = hash.begin(); i != hash.end(); i++)
        {
            int num = i->first;
            heap.push(num);
        }
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};