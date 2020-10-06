class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* left = head, *right = head;
        while(left){
            while(left->val == right->val){
                right = right->next;
                if(!right)  break;
            }
            if(!right)  left->next = NULL;
            if(right)   left->next = right;
            left = left->next;
        }
        return head;
    }
};
