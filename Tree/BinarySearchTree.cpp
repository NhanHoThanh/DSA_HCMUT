template <class T>
class BinaryTree
{
public:
    class Node;
    Node *root;
    BinaryTree() : root(nullptr);
    ~BinaryTree(){};

private:
    int size = 0;

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

    Node *deleteNode(Node *node, T value)
    {
        if (node == nullptr)
            return node;
        if (value < node->value)
            node->pLeft = deleteNode(node->pLeft, value);
        else if (value > node->value)
            node->pRight = deleteNode(node->pRight, value);
        else
        {
            if (node->pLeft == nullptr)
            {
                Node *temp = node->pRight;
                delete node;
                return temp;
            }
            else if (node->pRight == nullptr)
            {
                Node *temp = node->pLeft;
                delete node;
                return temp;
            }
            Node *temp = minValueNode(node->pRight);
            node->value = temp->value;
            node->pRight = deleteNode(node->pRight, temp->value);
        }
        return node;
    }

public:
    class Node
    {
    public:
        T val;
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

    class Iterator
    {
    private:
        stack<Node *> stack;
        void pushLeft(Node *node)
        {
            while (node != NULL)
            {
                stack.push(node);
                node = node->pLeft;
            }
        }

    public:
        Iterator(Node *root)
        {
            pushLeft(root);
        }

        bool hasNext()
        {
            return !stack.empty();
        }

        Node *next()
        {
            if (stack.empty())
            {
                return NULL;
            }

            Node *node = stack.top();
            stack.pop();

            if (node->pRight != NULL)
            {
                pushLeft(node->pRight);
            }

            return node;
        }
    };

    Iterator root()
    {
        return Iterator(root);
    }

    int height()
    {
        if (root == nullptr)
            return 0;

        int lheight = height(root->pLeft);
        int rheight = height(root->pRight);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }

    void levelOrderTranversal(std::function<void(Node *&)> func)
    {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            func(node);
            q.pop();

            if (node->pLeft != NULL)
                q.push(node->pLeft);
            if (node->pRight != NULL)
                q.push(node->pRight);
        }
    }
    void preOrderTranversal(std::function<void(Node *&)> func)
    {
        if (root == NULL)
            return;
        stack<*Node> s;
        s.push(root);
        while (!s.empty())
        {
            Node *node = s.top();
            func(node);
            s.pop();

            if (node->pRight != NULL)
                s.push(node->pRight);
            if (node->pLeft != NULL)
                s.push(node->pLeft);
        }
    }

    void inOrderTraversal(std::function<void(Node *&)> func)
    {
        if (root == NULL)
            return;
        stack<Node *> s;
        Node *curr = root;

        while (curr != NULL || !s.empty())
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->pLeft;
            }
            curr = s.top();
            s.pop();
            func(curr);
            curr = curr->pRight;
        }
    }

    void postOrderTraversal(std::function<void(Node *&)> func)
    {
        if (root == NULL)
            return;

        std::stack<Node *> s;
        s.push(root);
        Node *prev = NULL;

        while (!s.empty())
        {
            Node *curr = s.top();

            // case 1: we are moving down the tree.
            if (prev == NULL || prev->pLeft == curr || prev->pRight == curr)
            {
                if (curr->pLeft)
                    s.push(curr->pLeft);
                else if (curr->pRight)
                    s.push(curr->pRight);
            }

            // case 2: we are moving up the tree from the left.
            else if (curr->pLeft == prev)
            {
                if (curr->pRight)
                    s.push(curr->pRight);
            }

            // case 3: we are moving up the tree from the right.
            else
            {
                func(curr);
                s.pop();
            }

            prev = curr;
        }
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
    void deleteNode(T value)
    {
        root = deleteNode(root, value);
    }
};