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
    bool isPowerOfTwo(int n) {
        return n>=1 && ((n & (n-1)) == 0);
    }
};