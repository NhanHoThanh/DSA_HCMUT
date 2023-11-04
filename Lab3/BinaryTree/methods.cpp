template <class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node *walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.

    int getHeight(Node *n = nullptr)
    {
        if (n == nullptr)
            n = root;
        return max(n->pLeft ? getHeight(n->pLeft) : 0, n->pRight ? getHeight(n->pRight) : 0) + 1;
    }

    string getPreOrder(Node *node)
    {
        if (node == NULL)
            return "";
        return to_string(node->value) + " " + getPreOrder(node->pLeft) + getPreOrder(node->pRight);
    }

    string preOrder()
    {
        return getPreOrder(root);
    }

    string getInOrder(Node *node)
    {
        if (node == NULL)
            return "";
        return getInOrder(node->pLeft) + to_string(node->value) + " " + getInOrder(node->pRight);
    }

    string inOrder()
    {
        return getInOrder(root);
    }

    string getPostOrder(Node *node)
    {
        if (node == NULL)
            return "";
        return getPostOrder(node->pLeft) + getPostOrder(node->pRight) + to_string(node->value) + " ";
    }

    string postOrder()
    {
        return getPostOrder(root);
    }

    // STUDENT ANSWER END
    // STUDENT ANSWER END
};