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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* sentinel = new ListNode();
        ListNode* ans_tail = sentinel;
        while (1)
        {
            if (l1 == nullptr && l2 == nullptr)
            {
                if (carry == 0)
                {
                    break;
                }
                ans_tail->next = new ListNode(carry);
                break;
            }
            else if (l1 == nullptr)
            {
                int newval = l2->val + carry >= 10 ? (l2->val + carry - 10) : (l2->val + carry);
                carry = l2->val + carry >= 10 ? 1 : 0;
                l2 = l2->next;
                ans_tail->next = new ListNode(newval);
                ans_tail = ans_tail->next;
            }
            else if (l2 == nullptr)
            {
                int newval = l1->val + carry >= 10 ? (l1->val + carry - 10) : (l1->val + carry);
                carry = l1->val + carry >= 10 ? 1 : 0;
                l1 = l1->next;
                ans_tail->next = new ListNode(newval);
                ans_tail = ans_tail->next;
            }
            else
            {
                int newval = l1->val + l2->val + carry >= 10 ? (l1->val + l2->val + carry - 10) : (l1->val + l2->val + carry);
                carry = l1->val + l2->val + carry >= 10 ? 1 : 0;
                l1 = l1->next;
                l2 = l2->next;
                ans_tail->next = new ListNode(newval);
                ans_tail = ans_tail->next;
            }
        }
        return sentinel->next;
    }
};