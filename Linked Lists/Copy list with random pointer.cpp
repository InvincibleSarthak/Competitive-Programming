class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>m;
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            m[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp){
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        return m[head];
    }
};
