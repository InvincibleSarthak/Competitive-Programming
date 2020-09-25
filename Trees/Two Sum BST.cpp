class Solution {
    int sum;
    bool ans = false;
    map<int,int>m;
public:
    void inOrder(TreeNode* root){
        if(!root)   return;
        if(m.find(sum - root->val) != m.end()){
            ans = true;
        }
        m[root->val]++;
        if(root->left)  inOrder(root->left);
        if(root->right) inOrder(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        sum = k;
        if(!root->left && !root->right) return false;
        inOrder(root);
        return ans;
    }
};
