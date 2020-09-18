class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(!root){
            return ans;
        }
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        bool order = true;
        vector<int>v;
        while(!s1.empty()){
            TreeNode* node = s1.top();
            s1.pop();
            if(node){
                v.push_back(node->val);
                if(order){
                    if(node->left)  s2.push(node->left);
                    if(node->right) s2.push(node->right);
                }
                else{
                    if(node->right) s2.push(node->right);
                    if(node->left)  s2.push(node->left);
                }
            }
            if(s1.empty()){
                ans.push_back(v);
                v.clear();
                order = !order;
                swap(s1,s2);
            } 
        }
        return ans;
    }
};
