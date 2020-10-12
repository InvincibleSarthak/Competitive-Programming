// half node - node with only one child


void removeNodes(TreeNode* root){
    if(!root)   return;
    if(root->left){
        if(root->left->left && !root->left->right){
            root->left = root->left->left;
        }
        if(!root->left->left && root->left->right){
            root->left = root->left->right;
        }
    }
    if(root->right){
        if(root->right->left && !root->right->right){
            root->right = root->right->left;
        }
        if(!root->right->left && root->right->right){
            root->right = root->right->right;
        }
    }
    removeNodes(root->left);
    removeNodes(root->right);
}
 
TreeNode* Solution::solve(TreeNode* A) {
    if(!A)  return NULL;
    if(!A->left && A->right)    A = A->right;
    if(A->left && !A->right)    A = A->left;
    
    removeNodes(A);
    return A;
}
