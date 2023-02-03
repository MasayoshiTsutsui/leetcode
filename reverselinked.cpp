struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pred = NULL;
        while (head != NULL)
        {
            ListNode* tmp_nexthead = head->next;
            head->next = pred;

            pred = head;
            head = tmp_nexthead;
        }
        return pred;
    }
};