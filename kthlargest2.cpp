#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class KthLargest {
private:
    int myk;
    priority_queue<int, vector<int>, greater<int> > heap;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            heap.push(nums.at(i));
        }
        while (heap.size() > k)
        {
            heap.pop();
        }
        myk = k;
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > myk) {
            heap.pop();
        }
        return heap.top();
    }
};