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
        ListNode *node = head;
        int newestval = -101;
        ListNode ans(newestval);
        ListNode *cur_tail = &ans;

        while(node != NULL) {
            if (node->val > newestval) {
                if (node->next == NULL || node->val < node->next->val) {
                    cur_tail->next = node;
                    cur_tail = node;
                }
            }
            newestval = node->val;
            node = node->next;
        }
        
        cur_tail->next = NULL;
        return ans.next;
    }
};