class Solution {
    int ans = INT_MIN;
public:
    int solve(TreeNode* root){
        if(!root) return 0;
        int left, right;
        left = solve(root->left);
        right = solve(root->right);
        int temp = max(left,right);
        ans = max(left + right + root->val,ans);
        if(temp < 0)    temp = 0;
        ans = max(ans,temp+root->val);
        return temp+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int x = solve(root);
        return max(x,ans);
    }
};
