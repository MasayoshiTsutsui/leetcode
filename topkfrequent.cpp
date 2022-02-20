#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> countups;
        for (int num : nums) {
            auto p = countups.emplace(num, 1);
            if (p.second == false) {
                countups.at(num)++;
            }
        }

        auto comp = [&countups](int key1, int key2) {
            return countups.at(k1) > countups.at(k2)
        };

        unordered_set <int, vector<int>, decltype(heap)> heap(comp);

        for (pair<int, int> countup : countups) {
            heap.push(countup.first);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<int> ans(k);
        
        for (int i = k-1; i >= 0; i--)
        {
            ans.at(i) = heap.top();
            heap.pop();
        }
        return ans;
};