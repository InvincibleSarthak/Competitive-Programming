class Solution {
    long long int ans = 0;
    long long int totalSum = 0;
public:
    long long int sum(TreeNode* root){
        if(!root)   return 0;
        long long int l = 0, r = 0;
        if(root->left)  l = sum(root->left);
        if(root->right) r = sum(root->right);
        long long int temp = totalSum - l - r;
        ans = max(ans,max((temp+r)*l,(temp+l)*r));
        return root->val + l + r;
    }
    void inOrder(TreeNode* root){
        if(!root)   return;
        inOrder(root->left);
        totalSum += root->val;
        inOrder(root->right);
    }
    int maxProduct(TreeNode* root) {
        inOrder(root);
        long long int sar = sum(root);
        return ans%(1000000007);
    }
};
