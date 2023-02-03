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
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charInS;
        int ans = 0;
        int ansTemp = 0;
        int left = 0;
        int right = 0;
        while(right < s.size()) {
            char c = s.at(right);
            if (charInS.find(c) == charInS.end()) {
                charInS.insert(c);
                right++;
                ansTemp++;
                ans = max(ans, ansTemp);
            }
            else {
                charInS.erase(s.at(left));
                left++;
                ansTemp--;
            }
        }
        return ans;
    }
};