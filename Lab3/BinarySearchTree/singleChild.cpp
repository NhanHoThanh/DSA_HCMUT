void countnode(BSTNode *root, int &count)
{
    if (root == nullptr)
        return;

    if (root->left != nullptr && root->right == nullptr)
        count++;
    if (root->left == nullptr && root->right != nullptr)
        count++;

    countnode(root->left, count);
    countnode(root->right, count);
    if (left != nullptr && right != nullptr)
        return;
}

int singleChild(BSTNode *root)
{
    // STUDENT ANSWER
    int count = 0;
    countnode(root, count);
    return count;
}