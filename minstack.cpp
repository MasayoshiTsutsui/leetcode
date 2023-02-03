#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class MinStack {
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    MinStack() {}
    
    void push(int val) {
        stk1.push(val);
        if (stk2.size() == 0 || stk2.top() >= val) {
            stk2.push(val);
        }
    }
    
    void pop() {
        int poppingval = stk1.top();
        stk1.pop();
        if (poppingval == stk2.top()) {
            stk2.pop();
        }
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */