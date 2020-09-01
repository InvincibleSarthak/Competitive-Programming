//To print the level order traversal of a tree in spiral form

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
void spiralOrder(Node* root){
    if(root == NULL)    return;
    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* temp = s1.top();
            s1.pop();
            cout<<temp->data<<' ';
            if(temp->right) s2.push(temp->right);
            if(temp->left)  s2.push(temp->left);
        }
        while(!s2.empty()){
            Node* temp = s2.top();
            s2.pop();
            cout<<temp->data<<' ';
            if(temp->left) s1.push(temp->left);
            if(temp->right) s1.push(temp->right);
        }
    }
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    spiralOrder(root);
}
