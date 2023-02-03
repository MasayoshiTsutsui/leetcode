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
    bool isSubsequence(string s, string t) {
        int head = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s.at(head) == t.at(i)) {
                head++;
                if (head == s.size()) {
                    break;
                }
            }
        }
        if (head == s.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};