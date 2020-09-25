class Solution {
    size_t ans = 1;
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,size_t>>q;
        q.push({root,0});
        while(!q.empty()){
            ans = max(ans,q.back().second - q.front().second + 1);
            int n = q.size();
            for(int i=0;i<n;i++){
                pair<TreeNode*,size_t>p = q.front();
                TreeNode* temp = p.first;
                size_t x = p.second;
                q.pop();
                if(temp->left)  q.push({temp->left,2*x+1});
                if(temp->right) q.push({temp->right,2*x+2});
            }   
        }
        return ans;
    }
};
