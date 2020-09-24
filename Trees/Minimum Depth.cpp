class Solution {
    int ans = INT_MAX;
public:
    void solve(TreeNode* root, int depth){
        if(!root){   ans = 0; return;}
        if(!root->left && !root->right){
            ans = min(ans,depth);
            return;
        }
        if(root->left)  solve(root->left,depth+1);
        if(root->right) solve(root->right,depth+1);
        return;
    }
    int minDepth(TreeNode* root) {
        solve(root,1);
        return ans;
    }
};
