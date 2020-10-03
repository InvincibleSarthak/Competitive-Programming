class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        swap(temp->val,temp->next->val);
        ListNode* temp1 = temp->next;
        temp->next = temp1->next;
        delete(temp1);
    }
};
