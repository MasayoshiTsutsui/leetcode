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
        if (head == NULL) {
            return NULL;
        }
        ListNode* predhead = head;
        ListNode* nexthead = head->next;
        while (nexthead != NULL)
        {
            ListNode* nexthead_tmp = nexthead->next;
            nexthead->next = predhead;
            predhead = nexthead;
            nexthead = nexthead_tmp;
        }
        head->next = NULL;
        return predhead;
        
        
    }
};