#include<iostream>
#include<bits/stdc++.h>
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

bool check(Node* node, Node* &parent){
    if(node){
        if(!check(node->left,parent)) return false;
        if(parent != NULL && node->data < parent->data )  return false;
        parent = node;
        return check(node->right,parent);
    }
    return true;
}
int main(){
    Node* root = newNode(4);
    Node* temp = NULL;
    root->left = newNode(2);
    root->right = newNode(6); 
    root->left->left = newNode(1); 
    root->left->right = newNode(3); 
    root->right->left = newNode(5); 
    root->right->right = newNode(7); 
    if(check(root,temp))    cout<<"BST"<<'\n';
    else    cout<<"Not a BST"<<'\n';
}
