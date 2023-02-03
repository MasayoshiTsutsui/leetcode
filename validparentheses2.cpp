#include <string>
#include <stack>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        vector<char> opens;
        vector<char> closes;
        opens.push_back('(');
        opens.push_back('{');
        opens.push_back('[');
        closes.push_back(')');
        closes.push_back('}');
        closes.push_back(']');
        

        for (size_t i = 0; i < s.size(); i++)
        {
            char c = s.at(i);
            auto itr = find(closes.begin(), closes.end(), c);
            if (find(opens.begin(), opens.end(), c) != opens.end())
            {
                stk.push(c);
            }
            else if (itr != closes.end())
            {
                if (stk.size() > 0 && opens.at(distance(closes.begin(), itr)) == stk.top())
                {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (stk.size())
        {
            return false;
        }
        return true;
    }
};