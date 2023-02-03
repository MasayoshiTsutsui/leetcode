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
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);
 
            return h1 ^ h2;
        }
    };

    vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [&nums1, &nums2](pair<int, int> l, pair<int, int> r){
            return nums1.at(l.first) + nums2.at(l.second) > nums1.at(r.first) + nums2.at(r.second);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);

        heap.emplace(0, 0);

        vector<vector<int>> ans;

        unordered_set<pair<int, int>, pair_hash> set;

        while(!heap.empty() && ans.size() < k)
        {
            pair<int, int> indice = heap.top();
            heap.pop();
            vector<int> a = {nums1.at(indice.first), nums2.at(indice.second)};
            ans.push_back(a);
            if (indice.first+1 < nums1.size() && set.emplace(indice.first+1, indice.second).second)
            {
                heap.emplace(indice.first + 1, indice.second);
            }
            if (indice.second+1 < nums2.size() && set.emplace(indice.first, indice.second+1).second)
            {
                heap.emplace(indice.first, indice.second + 1);
            }
        }

        return ans;
    }
};