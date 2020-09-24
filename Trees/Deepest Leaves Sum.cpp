class Solution {
    int maxDepth = 0;
    int sum = 0;
public:
    void solve(TreeNode* root, int depth){
        if(!root->left && !root->right){
            if(depth == maxDepth){
                sum += root->val;
            }
            if(depth > maxDepth){
                sum = root->val;
                maxDepth = depth;
            }
        }
        if(root->left)  solve(root->left,depth+1);
        if(root->right) solve(root->right,depth+1);
        return ;
    }
    int deepestLeavesSum(TreeNode* root) {
        solve(root,1);
        return sum;
    }
};
