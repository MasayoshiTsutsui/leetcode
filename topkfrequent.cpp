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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_cnt;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums.at(i);
            if(!num_cnt.emplace(num, 1).second)
            {
                num_cnt.at(num)++;
            }
        }

        auto comp = [&](int l, int r)
        {
            return num_cnt.at(l) > num_cnt.at(r);
        };
        
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);

        for (auto itr = num_cnt.begin(); itr != num_cnt.end(); itr++)
        {
            int num = itr->first;
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