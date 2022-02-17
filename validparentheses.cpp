#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for (char c : s) {
            switch (c)
            {
            case '(':
                st.push('(');
                break;
            case '{':
                st.push('{');
                break;
            case '[':
                st.push('[');
                break;
            case ')':
                if(st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
                break;
            case '}':
                if(st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
                break;
            case ']':
                if(st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
                break;
            
            default:
                return false;
            }
        }
        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
        
    }
};