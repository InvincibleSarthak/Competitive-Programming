vector<int>ans;
bool solveLeaves(TreeNode* root, int k){
    if(!root)   return false;
    if(root->val == k){
        ans.push_back(root->val);
        return true;
    }
    if(!root->left && !root->right){
        return false;    
    } 
    bool left,right;
    ans.push_back(root->val);
    left = solveLeaves(root->left,k);
    right = solveLeaves(root->right,k);
    if((!left && right) || (left && !right)){
        return true;
    }
    else{
        ans.pop_back();
        return false;
    }
}

vector<int> Solution::solve(TreeNode* A, int B) {
    ans.clear();
    bool temp = solveLeaves(A,B);
    return ans;
}
