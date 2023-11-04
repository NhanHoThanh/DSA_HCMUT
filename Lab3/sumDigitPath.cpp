// failed hidden test

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

    void sumDigitPath(BTNode *root, int pre_sum, int &sum)
    {
        if (root == NULL)
            return;
        int cur_sum = (pre_sum * 10 + root->val) % 27022001;
        if (root->left == NULL && root->right == NULL)
        {
            sum = (sum + cur_sum) % 27022001;
        }
        else
        {
            sumDigitPath(root->left, cur_sum, sum);
            sumDigitPath(root->right, cur_sum, sum);
        }
    }
    int sumDigitPath(BTNode *root)
    {
        int sum = 0;
        sumDigitPath(root, 0, sum);
        return sum;
    }
};