class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        if(!l1 && !l2)  return NULL; 
        ListNode* head = new ListNode(0);
        ListNode* temp3 = head;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                temp3->next = temp1;
                temp3 = temp3->next;
                temp3->val = temp1->val;
                temp1 = temp1->next;
            }
            else{
                temp3->next = temp2;
                temp3 = temp3->next;
                temp3->val = temp2->val;
                temp2 = temp2->next;
            }
        }
        while(temp1){
            temp3->next = temp1;
            temp3 = temp3->next;
            temp3->val = temp1->val;
            temp1 = temp1->next;
        }
        while(temp2){
            temp3->next = temp2;
            temp3 = temp3->next;
            temp3->val = temp2->val;
            temp2 = temp2->next;
        }
        return head->next;
    }
};
