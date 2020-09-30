class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        while(temp1 || temp2){
            int a = (temp1 != NULL) ? temp1->val : 0;
            int b = (temp2 != NULL) ? temp2->val : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            if(temp1 != NULL)   temp1 = temp1->next;
            if(temp2 != NULL)   temp2 = temp2->next;
        }
        if(carry>0){
            temp->next = new ListNode(carry);
        }
        return ans->next;
    }
};
