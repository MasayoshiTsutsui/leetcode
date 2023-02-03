#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
#include <queue>


class KthLargest {
private:
        priority_queue<int, vector<int>, greater<int>> heap;
        int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums)
        {
            this->heap.push(num);
        }
        while(this->heap.size() > k)
        {
            this->heap.pop();
        }
    }
    
    int add(int val) {
        this->heap.push(val);
        while(this->heap.size() > k)
        {
            this->heap.pop();
        }
        return heap.top();
    }
};