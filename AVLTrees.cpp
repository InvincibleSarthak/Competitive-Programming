//Insertion

#include<iostream>
using namespace std;
class Node{
	public: 
		int key;
		Node* left;
		Node* right;
		int height;
};
int getHeight(Node* node){
	if(node == NULL) return 0;
	return node->height;
}
int getBalance(Node* node){
	int ans = (getHeight(node->left) - getHeight(node->right));
	return ans;
}
Node* newNode(int key){
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}
Node* rightRotate(Node* y){
	Node* x = y->left;
	Node* z = x->right;
	x->right = y;
	y->left = z;
	x->height = max(getHeight(x->left),getHeight(x->right))+1;
	y->height = max(getHeight(y->left),getHeight(y->right))+1;
	return x; 
}
Node* leftRotate(Node* x){
	Node* y = x->right;
	Node* z = y->left;
	y->left = x;
	y->right = z;
	x->height = max(getHeight(x->left),getHeight(x->right))+1;
	y->height = max(getHeight(y->left),getHeight(y->right))+1;
	return y;
}
Node* insertNode(Node* node, int val){
	if(node == NULL){
		node = newNode(val);
		return node;
	}
	if(val < (node->left)->key) return node->left;
	else if(val > (node->right)->key) return node->right;
	else return node;
	node->height = max(getHeight(node->left),getHeight(node->right))+1;
	int bal = getBalance(node);
	
	if(bal > 1 && val < (node->left)->key) return rightRotate(node);
	else if(bal > 1 && val > (node->left)->key){
		leftRotate(node->left); 
		return rightRotate(node);	
	} 
	else if(bal < -1 && val < (node->right)->key){
		rightRotate(node->right); 
		return leftRotate(node);	
	} 
	else if(bal < -1 && val > (node->right)->key) return leftRotate(node);
	
	return node;
}
int main(){
	int n;
	cin>>n;
	int val;
	Node* root =NULL;
	for(int i=0;i<n;i++){
		cin>>val;
		root = insertNode(root,val);
	}
}
