class Solution {
    int ans;
public:
    void inOrder(TreeNode* root, int &k){
        if(!root)   return;
        inOrder(root->left,k);
        k--;
        if(k == 0)  {ans = root->val; return;}
        inOrder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)   return 0;
        if(!root->left && !root->right) return root->val;
        inOrder(root,k);
        return ans;
    }
};
