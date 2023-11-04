Node *add(Node *node, T value)
{
    if (node == nullptr)
    {
        return new Node(value);
    }
    if (value < node->value)
    {
        node->pLeft = add(node->pLeft, value);
    }
    else
    {
        node->pRight = add(node->pRight, value);
    }
    return node;
}

void add(T value)
{
    root = add(root, value);
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->pLeft != nullptr)
        current = current->pLeft;
    return current;
}

Node *deleteNode(Node *root, T value)
{
    if (root == nullptr)
        return root;
    if (value < root->value)
        root->pLeft = deleteNode(root->pLeft, value);
    else if (value > root->value)
        root->pRight = deleteNode(root->pRight, value);
    else
    {
        if (root->pLeft == nullptr)
        {
            Node *temp = root->pRight;
            delete root;
            return temp;
        }
        else if (root->pRight == nullptr)
        {
            Node *temp = root->pLeft;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->pRight);
        root->value = temp->value;
        root->pRight = deleteNode(root->pRight, temp->value);
    }
    return root;
}

void deleteNode(T value)
{
    root = deleteNode(root, value);
}