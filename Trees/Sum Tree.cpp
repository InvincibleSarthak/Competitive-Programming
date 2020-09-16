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
int solve(Node* root){
    if(!root)   return 0;
    int temp = root->data;
    root->data = solve(root->left) + solve(root->right);
    return root->data + temp;
}
