class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(!head->next) return head->val;
        int ans = 0;
        ListNode* temp = head;
        while(temp){
            ans = (ans<<1) + temp->val;
            temp = temp->next;
        }
        return ans;
    }
};
