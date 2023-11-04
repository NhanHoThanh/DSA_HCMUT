#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class BSTNode
{
public:
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode()
    {
        this->left = this->right = nullptr;
    }
    BSTNode(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
    BSTNode(int val, BSTNode *&left, BSTNode *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    void kthSmallestUtil(BSTNode *root, int &k, int &result)
    {
        if (root == NULL || k < 0)
            return;

        kthSmallestUtil(root->left, k, result);

        k--;
        if (k == 0)
        {
            result = root->val;
            return;
        }

        kthSmallestUtil(root->right, k, result);
    }

    int kthSmallest(BSTNode *root, int k)
    {
        int result = -1;
        kthSmallestUtil(root, k, result);
        return result;
    }
};
