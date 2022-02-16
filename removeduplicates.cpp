 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 //
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* node = head->next;
        ListNode* cur_tail = head; //current tail
        while(node != NULL) {
            if (cur_tail->val < node->val) {
                cur_tail->next = node;
                cur_tail = node;
            }
            node = node->next;
        }
        cur_tail->next = NULL;
        return head;
        
    }
};
