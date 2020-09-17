//If sum of all nodes present from root to leaf = given K, return true


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        
        if(root->val == sum && root->left == NULL && root->right == NULL)   return true;
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
