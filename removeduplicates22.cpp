#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* nullhead = new ListNode(-999);
        ListNode* tail = nullhead;
        ListNode* cur = head;

        while (cur != nullptr)
        {
            bool dupl_found = false;
            cout << curr->val << endl;
            while (cur->next != nullptr && cur->next->val == cur->val)
            {
                dupl_found = true;
                cur = cur->next;
            }
            if (dupl_found) {
                cur = cur->next;
            }
            else {
                tail->next = cur;
                tail = cur;
                cur = cur->next;
            }
        }
        tail->next = nullptr;
        return nullhead->next;
    }
};