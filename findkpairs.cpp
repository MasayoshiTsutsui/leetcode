#include <queue>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        map<pair<int, int>, int> numidxsumset;

        auto comp = [&numidxsumset](pair<int, int> p1, pair<int, int> p2) {
            return numidxsumset.at(p1) > numidxsumset.at(p2);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> idxheap(comp);

        numidxsumset.emplace(make_pair(0, 0), nums1.at(0)+nums2.at(0));
        idxheap.push(make_pair(0, 0));


        for (int i = 0; i < k; i++)
        {
            if (idxheap.empty()) {
                break;
            }

            pair<int, int> minpairidx = idxheap.top();
            ans.push_back({nums1.at(minpairidx.first), nums2.at(minpairidx.second)});
            idxheap.pop();

            if (minpairidx.first + 1 < nums1.size()) {
                int num1 = nums1.at(minpairidx.first + 1);
                int num2 = nums2.at(minpairidx.second);
                auto ret = numidxsumset.emplace(make_pair(make_pair(minpairidx.first+1, minpairidx.second), num1+num2));
                if (ret.second) {
                    idxheap.emplace(minpairidx.first+1, minpairidx.second);
                }
            }

            if (minpairidx.second + 1 < nums2.size()) {
                int num1 = nums1.at(minpairidx.first);
                int num2 = nums2.at(minpairidx.second + 1);
                auto ret = numidxsumset.emplace(make_pair(make_pair(minpairidx.first, minpairidx.second+1), num1+num2));
                if (ret.second) {
                    idxheap.emplace(minpairidx.first, minpairidx.second+1);
                }
            }
        }
        return ans;
        
        
    }
};