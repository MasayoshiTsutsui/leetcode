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
        unordered_set<ListNode*> pointers;
        while(head != NULL) {
            if (pointers.find(head) != pointers.end()) {
                return head;
            }
            else {
                pointers.insert(head);
                head = head->next;
            }
        }
        return NULL;
    }
};