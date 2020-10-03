//Iterative Approach: O(n) time and O(1) memory.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* temp1 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp1;
        }
        return prev;
    }
};
