class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)   return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(!fast){
            head = head->next;
        }
        else if(!fast->next){
            ListNode* temp = head->next;
            head->next = temp->next;
            delete(temp);
        }
        else{
            while(fast->next){
                fast = fast->next;
                slow = slow->next;
            }
            if(slow->next == fast){
                slow->next = NULL;
                delete(fast);
            }
            else if(slow->next != fast){
                ListNode* temp = slow->next;
                slow->next = temp->next;
                delete(temp);
            }   
        }
        return head;
    }
};
