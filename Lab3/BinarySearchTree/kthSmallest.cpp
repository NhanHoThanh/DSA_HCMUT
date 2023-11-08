#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node()
    {
        this->left = this->right = nullptr;
    }
    Node(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
    Node(int val, Node *&left, Node *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    void kthSmallestUtil(Node *root, int &k, int &result)
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

    int kthSmallest(Node *root, int k)
    {
        int result = -1;
        kthSmallestUtil(root, k, result);
        return result;
    }
};
