#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        int ans = 0;
        for (int i = n-2; i >= 0; i--) {
            int ith_bit = (k >> i) & 1;
            if (i == 0 && ith_bit == 0) {
                ans ^= 1;
            }
            else {
                if (ith_bit == 1) {
                    ans ^= 1;
                }
            }
            cout << ith_bit << endl;
            cout << ans << endl;
        }
        return ans;
    }
};
int main() {
    cout << Solution().kthGrammar(2,1) << endl;
}
/*
0
01
0110
01101001
0110100110010110
*/ 