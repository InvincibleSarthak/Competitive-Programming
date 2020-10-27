//DFS for annotating parent of all the nodes, and then BFS to go to all the nodes at distance k from the target node.


class Solution {
    map<TreeNode*,TreeNode*>parent;
public:
    void dfs(TreeNode* node, TreeNode* p){
        if(!node)   return;
        parent[node] = p;
        if(node->left)  dfs(node->left,node);
        if(node->right) dfs(node->right,node);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root,NULL);
        
        map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(NULL);
        q.push(target);
        for(auto it: parent){
            visited[it.first] = false;
        }
        visited[target] = true;
        visited[NULL] = true;
        
        vector<int>ans;
        
        int dist = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node){
                if(!visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(!visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(!visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            else{
                if(dist == K){
                    while(!q.empty()){
                        TreeNode* it = q.front();
                        q.pop();
                        if(it)  ans.push_back(it->val);
                    }
                    return ans;
                }
                q.push(NULL);
                dist++;
            }
            q.pop();
        }
        return ans;
    }
};
