#include <iostream>
#include <string>
#include <queue>
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

    int longestPathSumUtil(BTNode *root, int &maxLen, int &maxSum, int curLen, int curSum)
    {
        if (root == NULL)
        {
            if (curLen > maxLen)
            {
                maxLen = curLen;
                maxSum = curSum;
            }
            else if (curLen == maxLen)
            {
                maxSum = max(maxSum, curSum);
            }
            return maxSum;
        }
        longestPathSumUtil(root->left, maxLen, maxSum, curLen + 1, curSum + root->val);
        longestPathSumUtil(root->right, maxLen, maxSum, curLen + 1, curSum + root->val);
        return maxSum;
    }

    int longestPathSum(BTNode *root)
    {
        int maxLen = 0;
        int maxSum = 0;
        return longestPathSumUtil(root, maxLen, maxSum, 0, 0);
    }
};
