int solve(Node* node, int &ans){
    if(!node)   return 0;
    
    int left = solve(node->left,ans);
    int right = solve(node->right,ans);
    
    ans = max(ans, 1 + left + right);
    return 1 + max(left,right);
}
int diameter(Node* node) {
    if(!node)   return 0;
    int ans = INT_MIN;
    int temp = solve(node,ans);
    return ans;
}
