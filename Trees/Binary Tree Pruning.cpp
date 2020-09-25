class Solution {
public:
    bool solve(TreeNode* root){
        bool left = false, right = false; 
        if(root->left)  left = solve(root->left);
        if(root->right) right = solve(root->right);
        if(!left)   root->left = NULL;
        if(!right)  root->right = NULL;
        return root->val == 1 || left || right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(solve(root)){
            return root;
        }
        return NULL;
    }
};
