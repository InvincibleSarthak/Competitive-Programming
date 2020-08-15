#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};
void preOrder(Node* root){
    if(root == NULL)    return;
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
}
void invertBinaryTree(Node* root){
    if(root == NULL)    return;
    swap(root->left,root->right);
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    invertBinaryTree(root);
    preOrder(root);
}
