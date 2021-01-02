ListNode* oddEvenList(ListNode* head) {
        if(!head)   return NULL;
        ListNode* oddHead = NULL;
        ListNode* oddTail = NULL;
        ListNode* evenHead = NULL;
        ListNode* evenTail = NULL;
        ListNode* temp = head;
        bool isOdd = true;
        while(temp){
            if(isOdd){
                if(!oddHead){
                    oddHead = oddTail = temp;
                }
                else{
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
                temp = temp->next;
                oddTail->next = NULL;
                
            }
            else{
                if(!evenHead){
                    evenHead = evenTail = temp;
                }
                else{
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
                temp = temp->next;
                evenTail->next = NULL;
            }
            isOdd = !isOdd;
        }
        
        oddTail->next = evenHead;
        return head;
    }
