 //* Definition for singly-linked list.
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
        ListNode *pred = NULL;
        ListNode *ans = l1;


        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;

            if (sum > 9) {
                carry = 1;
                l1->val = sum - 10;
            }
            else {
                carry = 0;
                l1->val = sum;
            }
            pred = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == NULL) {
            pred->next = l2;
            while(l2 != NULL) {
                int sum = l2->val + carry;
                if (sum > 9) {
                    carry = 1;
                    l2->val = sum - 10;
                }
                else {
                    carry = 0;
                    l2->val = sum;
                }
                pred = l2;
                l2 = l2->next;
            }
        }
        else if (l2 == NULL) {
            while(l1 != NULL) {
                int sum = l1->val + carry;
                if (sum > 9) {
                    carry = 1;
                    l1->val = sum - 10;
                }
                else {
                    carry = 0;
                    l1->val = sum;
                }
                pred = l1;
                l1 = l1->next;
            }
        }

        if (carry == 1) {
            ListNode last = new ListNode(1);
            pred->next = &last;
        } 
        return ans;
    }
};