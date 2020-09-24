class Solution {
public:
    void inOrder(TreeNode* root, vector<int>&vec){
        if(!root)   return;
        if(!root->left && !root->right){
            vec.push_back(root->val);
            return;
        }
        inOrder(root->left,vec);
        inOrder(root->right,vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>temp1;
        vector<int>temp2;
        inOrder(root1,temp1);
        inOrder(root2,temp2);
        int n = temp1.size();
        int m = temp2.size();
        if(m != n)  return false;
        for(int i=0;i<n;i++){
            if(temp1[i] != temp2[i]){
                return false;
            } 
        }
        return true;
    }
};
