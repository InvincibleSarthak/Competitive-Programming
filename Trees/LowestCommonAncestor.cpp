#include<iostream>
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
Node* lca(Node* node, int a, int b){
    if(node == NULL){
        return NULL;
    }
    else if(node->data > a && node->data > b){
        return lca(node->left,a,b);
    }
    else if(node->data < a && node->data < b){
        return lca(node->right,a,b);
    }
    else    return node;
}
int main(){
    Node* root = newNode(20);
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);
    int a,b,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        Node* node = lca(root,a,b);
        cout<<node->data<<'\n';
    }
    
}
