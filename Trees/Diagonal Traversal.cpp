vector<int> Solution::solve(TreeNode* A) {
    if (!A)
        return {};
    vector<int> result;
    queue<TreeNode*> que;
    que.push(A);
    while (!que.empty()) {
        TreeNode* front = que.front();
        que.pop();
        while (front) {
            result.push_back(front->val);

            if (front->left)
                que.push(front->left);
            front = front->right;
        }
    }
    return result;
}
