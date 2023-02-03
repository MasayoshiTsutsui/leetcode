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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_set<int64_t> ugly_set;
        priority_queue<int64_t> pque_large;
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pque_small;
        pque_large.push(1);
        pque_small.push(1);
        for (size_t i = 0; i < n; i++)
        {
            int64_t smallest = pque_small.top();
            pque_small.pop();
            for (size_t j = 0; j < primes.size(); j++)
            {
                int64_t new_ugly = smallest * primes.at(j);
                if (!ugly_set.insert(new_ugly).second) {
                    continue;
                }
                if (pque_large.size() >= n && new_ugly >= pque_large.top()) {
                    break;
                }
                pque_small.push(new_ugly);
                pque_large.push(new_ugly);
                while(pque_large.size() > n) {
                    pque_large.pop();
                }
            }
        }
        //while(!pque_large.empty()) {
            //cout << pque_large.top() << endl;
            //pque_large.pop();
        //}
        return pque_large.top();
    }
};

// 1,2,7,13,19
// 1,2,4,7,13,14,19,26,38
// 1,2,4,