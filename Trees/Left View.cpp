
vector<int>ans;
int mx = INT_MIN;
void solve(Node* root,int l){
    if(!root)   return;
    if( l > mx){
        ans.push_back(root->data);
        mx = l;
    }
    if(root->left)  solve(root->left,l+1);
    if(root->right) solve(root->right,l+1);
}
vector<int> leftView(Node *root)
{
    ans.clear();
    mx = INT_MIN;
    solve(root,0);
    return ans;
}
