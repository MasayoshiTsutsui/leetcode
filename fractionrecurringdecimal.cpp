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

    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string ans;
        if (numerator < 0 ^ denominator < 0) {
            ans += '-';
        }
        long long lnumerator = llabs((long long)(numerator));
        long long ldenominator = llabs((long long)(denominator));
        ans += to_string(lnumerator / ldenominator);
        long long r = lnumerator % ldenominator;
        if (r != 0) {
            ans += '.';
        }

        unordered_map<long long, int> rest_ansIdx;

        while(r != 0) {
            if (rest_ansIdx.find(r) != rest_ansIdx.end()) {
                ans.insert(rest_ansIdx.at(r), "(");
                ans += ')';
                break;
            }
            rest_ansIdx.emplace(r, ans.size());
            r *= 10;
            ans += to_string(r / ldenominator);
            r %= ldenominator;
        }
        return ans;
    }
};