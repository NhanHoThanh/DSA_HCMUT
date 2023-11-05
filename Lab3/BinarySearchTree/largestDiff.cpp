#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;

class BTNode
{
public:
    int val;
    BTNode *left;
    BTNode *right;
    BTNode()
    {
        this->left = this->right = NULL;
    }
    BTNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
    BTNode(int val, BTNode *&left, BTNode *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};
// Dont know how to add root node
int dfs(BTNode *node, int &maxDiff)
{
    if (node == nullptr)
    {
        return 99999;
    }
    if (node->left == nullptr && node->right == nullptr)
    {
        return node->val;
    }
    int val = min(dfs(node->left, maxDiff),
                  dfs(node->right, maxDiff));
    maxDiff = max(maxDiff, node->val - val);
    return min(val, node->val);
}
int largestDiff(BTNode *root)
{
    int maxDiff = -99999;
    dfs(root, maxDiff);
    return maxDiff;
}

// 0.8/1.0
/*
int dfs(BTNode *node, int &maxDiff) {
    if (node == nullptr) {
        return 0;  // return 0 instead of a large number
    }
    int val = min(dfs(node->left, maxDiff), dfs(node->right, maxDiff));
    maxDiff = max(maxDiff, abs(node->val - val));
    return min(val, node->val);
}

int largestDiff(BTNode *root) {
    int maxDiff = 0;  // initialize maxDiff to 0 instead of a large negative number
    dfs(root, maxDiff);
    return maxDiff;
}*/