class Solution {
    int ans = 0;
    int maxPath = 0;
public:
    int solve(TreeNode* root){
        if(!root)   return  0;
        int left = 0, right = 0;
        if(root->left)  left = solve(root->left);
        if(root->right) right = solve(root->right);
        int leftAns = 0, rightAns = 0;
        if(root->left && (root->left->val == root->val)){
            leftAns = left + 1;
        }
        if(root->right && (root->right->val == root->val)){
            rightAns = right + 1;
        }
        ans = leftAns + rightAns;
        int temp = max(leftAns,rightAns);
        maxPath = max(maxPath, max(ans,temp));
        return temp;
    }
    int longestUnivaluePath(TreeNode* root) {
        ans = solve(root);
        return max(maxPath,ans);
    }
};
