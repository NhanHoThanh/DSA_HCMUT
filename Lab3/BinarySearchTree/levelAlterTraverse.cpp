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
};

vector<int> levelAlterTraverse(Node *root)
{
    if (!root)
    {
        vector<int> ans;
        return ans;
    }

    stack<Node *> oddLevelStack;
    stack<Node *> evenLevelStack;
    vector<int> ans;

    int level = 1;
    evenLevelStack.push(root);

    while (!oddLevelStack.empty() || !evenLevelStack.empty())
    {
        if (level % 2 != 0)
        {
            while (!evenLevelStack.empty())
            {
                Node *top = evenLevelStack.top();
                evenLevelStack.pop();

                ans.push_back(top->val);
                if (top->left)
                {
                    oddLevelStack.push(top->left);
                }
                if (top->right)
                {
                    oddLevelStack.push(top->right);
                }
            }
        }
        else
        {
            while (!oddLevelStack.empty())
            {
                Node *top = oddLevelStack.top();
                oddLevelStack.pop();

                ans.push_back(top->val);
                if (top->right)
                {
                    evenLevelStack.push(top->right);
                }
                if (top->left)
                {
                    evenLevelStack.push(top->left);
                }
            }
        }

        ++level;
    }

    return ans;
}

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void tranverseTreeAndPushValueIntoVector(Node *root, vector<int> &arr, int level, bool leftToRight)
{
    if (root == NULL)
        return;
    if (level == 1)
        arr.push_back(root->val);
    else if (level > 1)
    {
        if (leftToRight)
        {
            tranverseTreeAndPushValueIntoVector(root->left, arr, level - 1, leftToRight);
            tranverseTreeAndPushValueIntoVector(root->right, arr, level - 1, leftToRight);
        }
        else
        {
            tranverseTreeAndPushValueIntoVector(root->right, arr, level - 1, leftToRight);
            tranverseTreeAndPushValueIntoVector(root->left, arr, level - 1, leftToRight);
        }
    }
}

vector<int> levelAlterTraverse(Node *root)
{
    vector<int> arr;
    int h = height(root);
    bool leftToRight = true;
    for (int i = 1; i <= h; i++)
    {
        tranverseTreeAndPushValueIntoVector(root, arr, i, leftToRight);
        leftToRight = !leftToRight;
    }
    return arr;
}