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
    int myAtoi(string s) {
        int head = 0;
        if (s.size() == 0) {
            return 0;
        }
        while(s.at(head) == ' ') {
            head++;
            if (s.size() == head) {
                return 0;
            }
        }
        int isNeg = 0;
        if (s.at(head) == '-') {
            isNeg = 1;
            head++;
        }
        else if (s.at(head) == '+') {
            head++;
        }
        if (head >= s.size() || s.at(head) > '9' || s.at(head) < '0') {
            return 0;
        }
        else if (s.at(head))
        int ans = 0;
        bool flowable = false;
        bool surelyflow = false;

        for (int i = head; i < s.size(); i++)
        {
            if (s.at(i) > '9' || s.at(i) < '0') {
                break;
            }
            if (surelyflow) {
                if (isNeg) {
                    return INT_MIN;
                }
                else {
                    return INT_MAX;
                }
            }
            int digit = s.at(i) - '0';
            if (flowable) {
                if (isNeg) {
                    if (INT_MIN + digit >= ans * 10) {
                        return INT_MIN;
                    }
                    else {
                        ans = ans * 10 - digit;
                        surelyflow = true;
                    }
                }
                else {
                    if (INT_MAX - digit <= ans * 10) {
                        return INT_MAX;
                    }
                    else {
                        ans = ans * 10 + digit;
                        surelyflow = true;
                    }
                }
            }
            else {
                if (isNeg) {
                    ans = ans * 10 - digit;
                    if (INT_MIN / 10 > ans) {
                        surelyflow = true;
                    }
                    if ((INT_MIN + 9) / 10 >= ans) {
                        flowable = true;
                    }
                }
                else {
                    ans = ans * 10 + digit;
                    if (INT_MAX / 10 < ans) {
                        surelyflow = true;
                    }
                    if ((INT_MAX - 9) / 10 <= ans) {
                        flowable = true;
                    }
                }
            }
        }
        return ans;
    }
};