int dfs(BTNode *node, int &count)
{
    if (node == nullptr)
    {
        return -99999;
    }
    int leftMax = dfs(node->left, count);
    int rightMax = dfs(node->right, count);
    if (node->val >= leftMax && node->val >= rightMax)
    {
        count++;
    }
    return max(node->val, max(leftMax, rightMax));
}
int greatAncestor(BTNode *root)
{
    int count = 0;
    dfs(root, count);
    return count;
}