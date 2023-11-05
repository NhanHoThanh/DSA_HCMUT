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

int reverseInOrder(BTNode *node, int sum)
{
    if (node == nullptr)
    {
        return sum;
    }
    sum = reverseInOrder(node->right, sum);
    node->val += sum;
    sum = reverseInOrder(node->left, node->val);
    return sum;
}

BTNode *enlarge(BTNode *root)
{
    reverseInOrder(root, 0);
    return root;
}