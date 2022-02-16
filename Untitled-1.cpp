#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;
#define ll long long


class Solution {
    public:
        bool hasCycle(ListNode *head) {
            unordered_set<ListNode*> pointers;
            while (head != NULL)
            {
                if (pointers.find(head) != pointers.end()) {
                    return true;
                }
                else {
                    pointers.insert(head);
                    head = head->next;
                }
            }
            return false;
        }
};