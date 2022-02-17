#include <queue>
#include <vector>
class KthLargest {
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (int num : nums) 
        {
            this->queue.push(num);
        }

        while (queue.size() > k)
        {
            this->queue.pop();
        }
    }
    
    int add(int val) {
        this->queue.push(val);
        if(queue.size() > this->k) {
            queue.pop();
        }
        return queue.top();
    }
};