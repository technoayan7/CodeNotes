class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = new ListNode(-1);
        ListNode* newHead = prev;
        while(curr != NULL) {
            bool flag = 0;
            while(curr->next != NULL and curr->val == curr->next->val) {
                flag = 1;
                curr = curr->next;
            }
            if(flag == 0) {
                prev->next = curr;
                prev = prev->next;
            }
            curr = curr->next;
        }
        return newHead->next;
    }
};