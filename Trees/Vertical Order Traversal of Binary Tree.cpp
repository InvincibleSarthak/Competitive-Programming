class Solution {
    map<int,map<int,set<int>>> place;
    vector<vector<int>> ans;
public:
    void solve(TreeNode* root){
        int x,y;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>p = q.front();
            TreeNode* temp = p.first;
            pair<int,int>co = p.second;
            x = co.first;
            y = co.second;
            place[x][y].insert(temp->val);
            q.pop();
            if(temp->left)  q.push(make_pair(temp->left,make_pair(x-1,y+1)));
            if(temp->right) q.push(make_pair(temp->right,make_pair(x+1,y+1)));
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root);
        vector<int>temp;
        for(auto it: place){
            for(auto i: it.second){
                for(auto x: i.second){
                    temp.push_back(x);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
