int dfs(BTNode *node, int &count)
{
    if (node == nullptr)
    {
        return 0;
    }
    int leftSum = dfs(node->left, count);
    int rightSum = dfs(node->right, count);
    if (node->left && node->right && ((leftSum % 2 == 0 && rightSum % 2 == 1) || (leftSum % 2 == 1 && rightSum % 2 == 0)))
    {
        count++;
    }
    return node->val + leftSum + rightSum;
}

int distinctParities(BTNode *root)
{
    int count = 0;
    dfs(root, count);
    return count;
}