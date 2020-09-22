class Solution {
public:
    bool check(TreeNode* node, TreeNode* target){
        if(node && target){
            return check(node->left,target->left) && check(node->right,target->right);
        }
        else if(node || target){
            return false;
        }
        else{
            return true;
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* temp;
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp->val == target->val && check(temp,target))  return temp;
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return temp;
    }
};
