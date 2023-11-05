#include <unordered_set>
bool dfs(BSTNode *node, std::unordered_set<int> &set, int k)
{
    if (node == nullptr)
    {
        return false;
    }
    if (set.count(k - node->val))
    {
        return true;
    }
    set.insert(node->val);
    return dfs(node->left, set, k) || dfs(node->right, set, k);
}
bool findTarget(BSTNode *root, int k)
{
    std::unordered_set<int> set;
    return dfs(root, set, k);
}
