BSTNode *subtreeWithRange(BSTNode *root, int lo, int hi)
{
    if (root == nullptr)
        return nullptr;
    if (root->val < lo)
    {
        BSTNode *rChild = subtreeWithRange(root->right, lo, hi);
        return rChild;
    }
    if (root->val > hi)
    {
        BSTNode *lChild = subtreeWithRange(root->left, lo, hi);
        return lChild;
    }
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);

    return root;
}
