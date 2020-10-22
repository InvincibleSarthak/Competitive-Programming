/*
Given a binary tree. First print all leaf nodes, after that remove all the leaf nodes from the tree and now print all the new formed leaf nodes 
and keep doing this until all the nodes are removed from the tree.
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  int order;
  Node* left;
  Node* right;
};
vector<pair<int,int>>ans;
Node* newNode(int data, int order){
    Node* node = new Node; 
    node->data = data; 
    node->order = order; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
}
void postOrder(Node* root){
    if(!root){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    
    if(!root->left && !root->right){
        root->order = 1;
    }
    else if(root->left && root->right){
        root->order = max(root->left->order, root->right->order) + 1;
    }
    else{
        root->order = (root->left ? root->left->order : root->right->order) + 1;
    }
    ans.push_back({root->order,root->data});
}

void solve(){
    sort(ans.begin(),ans.end());
    int temp = 1;
    for(auto it: ans){
        if(it.first == temp){
            cout<<it.second<<' ';
        }
        else{
            temp++;
            cout<<'\n';
            cout<<it.second<<' ';
        }
    }
}
int main(){
    Node* root = newNode(8, 0); 
    root->left = newNode(3, 0); 
    root->right = newNode(10, 0); 
    root->left->left = newNode(1, 0); 
    root->left->right = newNode(6, 0); 
    root->right->left = newNode(14, 0); 
    root->right->right = newNode(4, 0); 
    root->left->left->left = newNode(7, 0); 
    root->left->left->right = newNode(13, 0); 
    postOrder(root);
    solve();
}
