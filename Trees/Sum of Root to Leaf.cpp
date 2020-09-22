

class Solution {
public:
    int ans = 0;
    void preOrder(TreeNode* root, int temp){
        if(!root)   return;
        if(root){
            temp = temp<<1 | root->val;
            if(root->left == NULL && root->right == NULL)   ans += temp;
            preOrder(root->left,temp);
            preOrder(root->right,temp);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        preOrder(root,0);
        return ans;
    }
    
};
