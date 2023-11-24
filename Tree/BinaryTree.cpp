#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

template <class K, class V = K>
class BinaryTree {
   public:
    class Node;
    Node *root;
    BinaryTree() : root(nullptr);
    ~BinaryTree(){};

   private:
    int size = 0;

   public:
    class Node {
       private:
        K key;
        V value;
        int height;
        Node *pLeft;
        Node *pRight;
        friend class BinaryTree<K, V>;

       public:
        Node(K key, V value) : this->key(key), this->value(value), pLeft(NULL), pRight(NULL), height(1){};
        ~Node(){};
    };

    class Iterator {
       private:
        stack<Node *> stack;
        void pushLeft(Node *node) {
            while (node != NULL) {
                stack.push(node);
                node = node->pLeft;
            }
        }

       public:
        Iterator(Node *root) {
            pushLeft(root);
        }

        bool hasNext() {
            return !stack.empty();
        }

        Node *next() {
            if (stack.empty()) {
                return NULL;
            }

            Node *node = stack.top();
            stack.pop();

            if (node->pRight != NULL) {
                pushLeft(node->pRight);
            }

            return node;
        }
    };

    Iterator root() {
        return Iterator(root);
    }

    int height() {
        if (root == nullptr)
            return 0;

        int lheight = height(root->pLeft);
        int rheight = height(root->pRight);

        if (lheight > rheight) {
            return (lheight + 1);
        } else {
            return (rheight + 1);
        }
    }

    void addNode(string posFromRoot, K key, V value) {
        if (posFromRoot == "") {
            this->root = new Node(key, value);
            size++;
            return;
        }
        Node *walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++) {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L') {
            if (walker->pLeft != NULL) {
                delete walker->pLeft;
            }
            walker->pLeft = new Node(key, value);
        }
        if (posFromRoot[l - 1] == 'R') {
            if (walker->pRight != NULL) {
                delete walker->pRight;
            }
            walker->pRight = new Node(key, value);
        }
        size++;
    }
    void levelOrderTranversal(std::function<void(Node *&)> func) {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            func(node);
            q.pop();

            if (node->pLeft != NULL)
                q.push(node->pLeft);
            if (node->pRight != NULL)
                q.push(node->pRight);
        }
    }
    void preOrderTranversal(std::function<void(Node *&)> func) {
        if (root == NULL)
            return;
        stack<*Node> s;
        s.push(root);
        while (!s.empty()) {
            Node *node = s.top();
            func(node);
            s.pop();

            if (node->pRight != NULL)
                s.push(node->pRight);
            if (node->pLeft != NULL)
                s.push(node->pLeft);
        }
    }

    void inOrderTraversal(std::function<void(Node *&)> func) {
        if (root == NULL)
            return;
        stack<Node *> s;
        Node *curr = root;

        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->pLeft;
            }
            curr = s.top();
            s.pop();
            func(curr);
            curr = curr->pRight;
        }
    }

    void postOrderTraversal(std::function<void(Node *&)> func) {
        if (root == NULL)
            return;

        std::stack<Node *> s;
        s.push(root);
        Node *prev = NULL;

        while (!s.empty()) {
            Node *curr = s.top();

            // case 1: we are moving down the tree.
            if (prev == NULL || prev->pLeft == curr || prev->pRight == curr) {
                if (curr->pLeft)
                    s.push(curr->pLeft);
                else if (curr->pRight)
                    s.push(curr->pRight);
            }

            // case 2: we are moving up the tree from the left.
            else if (curr->pLeft == prev) {
                if (curr->pRight)
                    s.push(curr->pRight);
            }

            // case 3: we are moving up the tree from the right.
            else {
                func(curr);
                s.pop();
            }

            prev = curr;
        }
    }
    void deleteNode(K key) {
        if (root == NULL)
            return;
        Node *key_node = NULL;
        levelOrderTranversal([&](Node *&node) {
            if (node->key == key)
            {
                key_node = node;
            } });

        if (key_node != NULL) {
            Node *curr = root;
            Node *parent = NULL;

            while (curr && curr->pRight != NULL) {
                parent = curr;
                curr = curr->pRight;
            }
            key_node->key = curr->key;
            key_node->value = curr->value;

            if (parent != NULL) {
                if (parent->pRight == curr) {
                    parent->pRight = curr->pRight;
                } else {
                    parent->pLeft = curr->pRight;
                }
            }
            delete curr;
            curr = NULL;
        }
    }
    void findNodeAndReplaceWith(Node *node) {
        if (root == NULL)
            return;
        Node *key_node = NULL;
        levelOrderTranversal([&](Node *&node) {
            if (node->key == key)
            {
                key_node = node;
            } });
        if (key_node != NULL) {
            if (key_node->key == key_node->value) {
                key_node->key = node->key;
                key_node->value = node->value;
            } else {
                key_node->value = node->value;
            }
        }
    }
};
