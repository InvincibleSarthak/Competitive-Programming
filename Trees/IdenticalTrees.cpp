//To check whether the two given trees are identical or not


#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int identicalTrees(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    else if( root1 != NULL && root2 != NULL){
        return (
            root1->data == root2->data &&
            identicalTrees(root1->left,root2->left) &&
            identicalTrees(root1->right,root2->right)
        );
    }
    else{
        return 0;
    }
}
int main() {
    Node *root1 = newNode(1);  
    Node *root2 = newNode(1);  
    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->left->left = newNode(4);  
    root1->left->right = newNode(5);  
  
    root2->left = newNode(2);  
    root2->right = newNode(3);  
    root2->left->left = newNode(4);  
    root2->left->right = newNode(6);

    if(identicalTrees(root1,root2)){
        cout<<"Identical"<<'\n';
    }
    else    cout<<"Not Identical"<<'\n';
}
