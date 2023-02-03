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
    vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<unordered_set<int> > map(nums1.size());
        vector<vector<int> > ans;
        auto comp = [&nums1, &nums2](pair<int, int>p1, pair<int, int>p2) {
            return nums1.at(p1.first) + nums2.at(p1.second) > nums1.at(p2.first) + nums2.at(p2.second);
        };

        priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(comp)> heap(comp);
        heap.emplace(0,0);
        map.at(0).insert(0);

        for (int i = 0; !heap.empty() && i < k; i++) {
            pair<int,int> idxpair = heap.top();
            heap.pop();
            int idx1 = idxpair.first;
            int idx2 = idxpair.second;
            vector<int> a = {nums1.at(idx1), nums2.at(idx2)};
            ans.push_back(a);
            if (idx2 + 1 < nums2.size() && map.at(idx1).find(idx2+1) == map.at(idx1).end()) {
                map.at(idx1).insert(idx2+1);
                heap.emplace(idx1, idx2+1);
            }
            if (idx1 + 1 < nums1.size() && map.at(idx1+1).find(idx2) == map.at(idx1+1).end()) {
                map.at(idx1+1).insert(idx2);
                heap.emplace(idx1+1, idx2);
            }
        }
        return ans;
    }
};