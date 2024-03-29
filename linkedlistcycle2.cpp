#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;
#define ll long long


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> node_log;
        

        if (head == NULL) {
            return NULL;
        }
        
        while(node_log.insert(head).second) {
            if (head->next == NULL) {
                return NULL;
            }
            head = head->next;
        }
        return head;
    }
};