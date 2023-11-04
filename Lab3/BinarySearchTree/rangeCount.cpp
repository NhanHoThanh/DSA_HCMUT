#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
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
void tranverseTree(BTNode *root, int &count, int lo, int hi)
{
    if (root == NULL)
    {
        return;
    }
    tranverseTree(root->left, count, lo, hi);
    if (root->val >= lo && root->val <= hi)
    {
        count++;
    }
    tranverseTree(root->right, count, lo, hi);
}
int rangeCount(BTNode *root, int lo, int hi)
{
    int count = 0;
    tranverseTree(root, count, lo, hi);
    return count;
}