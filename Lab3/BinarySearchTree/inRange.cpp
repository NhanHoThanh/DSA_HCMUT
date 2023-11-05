void dfs(BSTNode *node, int lo, int hi, int &count)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->val >= lo && node->val <= hi)
    {
        count++;
    }
    if (node->val > lo)
    {
        dfs(node->left, lo, hi, count);
    }
    if (node->val < hi)
    {
        dfs(node->right, lo, hi, count);
    }
}
int inRange(BSTNode *root, int lo, int hi)
{
    int count = 0;
    dfs(root, lo, hi, count);
    return count;
}