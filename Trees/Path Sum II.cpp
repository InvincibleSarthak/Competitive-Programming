//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum and then return the path.


class Solution {
public:
    void solve(TreeNode* root, int sum, vector<int>&path, vector<vector<int>>&ans){
        sum -= root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && sum == 0){
            ans.push_back(path);
        }
        if(root->left)  solve(root->left,sum,path,ans);
        if(root->right) solve(root->right,sum,path,ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ans;
        if(!root)   return ans;
        vector<int>path;
        solve(root,sum,path,ans);
        return ans;
    }
};
