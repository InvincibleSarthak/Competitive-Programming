struct Info {
    int size;
    int mx;
    int mn;
    int sum;
    bool isBST;
};
class Solution {
public:
    int ans = 0;
    Info* solve(TreeNode* root){
        if(!root){
            Info* temp = new Info();
            temp->size = 0;
            temp->mx = INT_MIN;
            temp->mn = INT_MAX;
            temp->sum = 0;
            temp->isBST = false;
            return temp;
        }
        if(!root->left && !root->right){
            Info* temp = new Info();
            temp->size = 1;
            temp->mx = root->val;
            temp->mn = root->val;
            temp->sum = root->val;
            ans = max(ans,temp->sum);
            temp->isBST = true;
            return temp;
        }
        Info *left = solve(root->left);
        Info *right = solve(root->right);
        
        Info* temp = new Info();
        temp->size = 1 + left->size + right->size;
        if((left->isBST && right->size == 0) && root->val > left->mx){
            temp->mx = root->val;
            temp->mn = left->mn;
            temp->sum = left->sum + root->val;
            ans = max(ans,temp->sum);
            temp->isBST = true;
            return temp;
        }
        if((right->isBST && left->size == 0) && root->val < right->mn){
            temp->mx = right->mx;
            temp->mn = root->val;
            temp->sum = right->sum + root->val;
            ans = max(ans,temp->sum);
            temp->isBST = true;
            return temp;
        }
        if(left->isBST && right->isBST && (left->mx < root->val && right->mn > root->val)){
            temp->mx = max({left->mx,right->mx,root->val});
            temp->mn = min({left->mn,right->mn,root->val});
            temp->sum = left->sum + right->sum + root->val;
            ans = max(ans,temp->sum);
            temp->isBST = true;
            return temp;
        }
        temp->sum = 0;
        temp->isBST = false;
        return temp;
    }
    int maxSumBST(TreeNode* root) {
        Info *temp = solve(root);
        return ans;
    }
};
