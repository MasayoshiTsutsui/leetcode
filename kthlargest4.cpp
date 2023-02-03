#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (size_t i = 0; i < nums.size(); i++)
        {
            this->heap.push(nums.at(i));
        }
        while (this->heap.size() > this->k)
        {
            heap.pop();
        }
    }
    int add(int val) {
        heap.push(val);
        while (this->heap.size() > this->k)
        {
            heap.pop();
        }
        return heap.top();
    }

};