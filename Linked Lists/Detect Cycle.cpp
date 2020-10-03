//Make a hash map of memory addresses of the nodes, if the same memory is accessed again, return true


class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>m;
        ListNode* temp = head;
        while(temp){
            if(m.find(temp) != m.end()){
                return true;
            }
            else    m[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};
