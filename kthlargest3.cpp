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
    priority_queue<int, vector<int>, greater<int> > heap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int i = 0; i < nums.size(); i++)
        {
            this->heap.push(nums.at(i));
        }

        while (this->heap.size() > k)
        {
            this->heap.pop();
        }
    }
    
    int add(int val) {
        this->heap.push(val);
        while (this->heap.size() > this->k)
        {
            this->heap.pop();
        }
        return heap.top();
    }
};