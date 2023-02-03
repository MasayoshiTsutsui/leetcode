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
    int numSquares(int n) {
        vector<int> sqrsTable(n+1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (i - j*j < 0) {
                    break;
                }
                if (sqrsTable.at(i) == 0) {
                    sqrsTable.at(i) = sqrsTable.at(i - j*j) + 1;
                }
                else {
                    sqrsTable.at(i) = min(sqrsTable.at(i - j*j) + 1, sqrsTable.at(i));
                }
            }
        }
        return sqrsTable.at(n);
    }
};