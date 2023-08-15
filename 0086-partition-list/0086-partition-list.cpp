class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> pre, pos;
        ListNode* temp = head;
        ListNode* ans = temp;
        while(temp != NULL) {
            int val = temp->val;
            if(val < x) pre.push_back(val);
            else pos.push_back(val);
            temp = temp->next;
        }
        temp = head;
        for(auto it: pre){
            temp->val = it;
            temp=temp->next;
        }
        for(auto it: pos){
            temp->val = it;
            temp=temp->next;
        }
        return ans;
    }
};