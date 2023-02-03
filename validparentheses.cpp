#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (size_t i = 0; i < s.size(); i++)
        {
            char c = s.at(i);
            
            if (c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }
            else
            {
                if (c == ')')
                {
                    if (!stk.empty() && stk.top() == '(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if (c == '}')
                {
                    if (!stk.empty() && stk.top() == '{')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                if (c == ']')
                {
                    if (!stk.empty() && stk.top() == '[')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (stk.empty())
        {
            return true;
        }
        return false;
    }
};