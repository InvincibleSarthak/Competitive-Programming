vector<int>ans;
void printLeft(Node* node){
    if(!node)   return;
    if(node->left)  ans.push_back(node->data),printLeft(node->left);
    else if (node->right)  ans.push_back(node->data),printLeft(node->right);
}
void printLeaves(Node* node){
    if(!node)   return;
    
    printLeaves(node->left);
    if(!node->left && !node->right) ans.push_back(node->data);
    printLeaves(node->right);
}
void printRight(Node* node){
    if(!node)   return;
    if(node->right){
        printRight(node->right);
        ans.push_back(node->data);
    }
    else if(node->left){
        printRight(node->left);
        ans.push_back(node->data);
    }
}
void solve(Node* node){
    if(!node)   return ;
    ans.push_back(node->data);
    printLeft(node->left);
    printLeaves(node->left);
    printLeaves(node->right);
    printRight(node->right);
}
vector <int> printBoundary(Node *root)
{
     ans.clear();
     solve(root);
     return ans;
     
}
