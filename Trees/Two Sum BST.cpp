//Approach 1 : In-order Traversal 
// time: O(n) space: O(n)
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


//Approach 2: Iterative
//time: O(n) space: O(h)
int Solution::t2Sum(TreeNode* head, int k) {
    TreeNode* start = head, *end = head, *temp = head;
    stack<TreeNode*>sleft,sright;
    while(temp){
        sleft.push(temp);
        temp = temp->left;
    }
    start = sleft.top();
    temp = head;
    while(temp){
        sright.push(temp);
        temp = temp->right;
    }
    end = sright.top();
    
    int sum;
    while(start != end){
        sum = start->val + end->val;
        if(sum == k){
            return 1;
        }
        else if(sum < k){
            temp = sleft.top();
            sleft.pop();
            if(temp->right){
                temp = temp->right;
                while(temp){
                    sleft.push(temp);
                    temp = temp->left;
                }
            }
            start = sleft.top();
        }
        else{
            temp = sright.top();
            sright.pop();
            if(temp->left){
                temp = temp->left;
                while(temp){
                    sright.push(temp);
                    temp = temp->right;
                }
            }
            end = sright.top();
        }
        
    }
    return 0;
}
