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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 1; i <= n; i++)
        {
            if (citations.at(n-i) < i) {
                return i - 1;
            }
        }
        return n;
    }
};