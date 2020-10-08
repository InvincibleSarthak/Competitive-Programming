// In case, last elements of both the lists, are not same, there is no intersection.
// Detecting intersection of linked lists by traversing List A and B by both the pointers. The moment they meet, it's the intersection point.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA, *tempB = headB, *lastA, *lastB;
        while(tempA){
            if(!tempA->next)    lastA = tempA;
            tempA = tempA->next;
        }
        while(tempB){
            if(!tempB->next)    lastB = tempB;
            tempB = tempB->next;
        }
        
        if(lastA != lastB)  return NULL;
        tempA = headA,tempB = headB;
        while(tempA && tempB){
            if(tempA == tempB)  return tempA;
            if(!tempA->next)    tempA = headB;
            else    tempA = tempA->next;
            
            if(!tempB->next)    tempB = headA;
            else    tempB = tempB->next;
        }
        return NULL;
    }
};
