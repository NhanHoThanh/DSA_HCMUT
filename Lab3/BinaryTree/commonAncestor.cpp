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

#include <vector>

    bool findPath(BTNode *root, vector<int> &path, int k)
    {
        if (root == NULL)
            return false;
        path.push_back(root->val);

        if (root->val == k)
            return true;

        if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
            return true;

        path.pop_back();
        return false;
    }
    int lowestAncestor(BTNode *root, int a, int b)
    {
        vector<int> path1, path2;

        if (!findPath(root, path1, a) || !findPath(root, path2, b))
            return -1;

        int i;
        for (i = 0; i < static_cast<int>(path1.size()) && i < static_cast<int>(path2.size()); i++)
            if (path1[i] != path2[i])
                break;
        return path1[i - 1];
    }
};