
void removeLoop(Node* head)
{
    Node* slow = head, *fast = head, *prev, *temp;
    while(fast && fast->next){
        slow = slow->next;
        prev = fast->next;
        fast = prev->next;
        if(slow == fast){
            temp = slow;
            break;
        }
    }
    if(!temp)   return;
    
    slow = head;
    while(slow != temp){
        prev = temp;
        slow = slow->next;
        temp = temp->next;
    }
    
    prev->next = NULL;
    return ;
}
