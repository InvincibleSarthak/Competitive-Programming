map<int,pair<int,int>>m;
void solve(Node *root, int dist, int level){
    if(root == NULL)    return;
    
    if(m.count(dist) == 0){
        m[dist]={root->data,level};
    }
    else if(m[dist].second > level){
        m[dist]={root->data,level};
    }
    solve(root->left,dist-1,level+1);
    solve(root->right,dist+1,level+1);
}
void topView(struct Node *root)
{
    solve(root,0,0);
    for(auto it: m ){
        cout<<it.second.first<<' ';
    }
    m.clear();
}
