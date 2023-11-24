#include <math.h>

#include <iostream>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue {
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n) {
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n) {
    cout << n << " ";
}

template <class T>
class AVLTree {
   public:
    class Node;

   private:
    Node *root;

   protected:
    int getHeightRec(Node *node) {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }

   public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}
    int getHeight() {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure() {
        int height = this->getHeight();
        if (this->root == NULL) {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp == NULL) {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            } else {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode) {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value);

    int getBalance(Node *subroot) {
        if (!subroot) return 0;
        return getHeightRec(subroot->pLeft) - getHeightRec(subroot->pRight);
    }

    Node *rotateLeft(Node *subroot)

    {
        // TODO: Rotate and return new root after rotate
        Node *y = subroot->pRight;
        Node *T2 = y->pLeft;
        subroot->pLeft = subroot;
        subroot->pRight = T2;
        subroot->height = max(height(x->left),
                              height(x->right)) +
                          1;
        y->height = max(height(y->left),
                        height(y->right)) +
                    1;
        return y;
    };

    Node *rotateRight(Node *subroot)

    {
        Node *y = subroot->pLeft;
        Node *T2 = y->pRight;

        // TODO: Rotate and return new root after rotate
    };
    void insert(Node *root, T &value) {
        if (node == NULL)
            return (new Node(key));

        if (value < node->data)
            node->pLeft = insert(node->pLeft, value);
        else if (value >= node->data)
            node->pRight = insert(node->pRight, value);

        int balance = getBalance(node);
        // LEFT LEFT
        if (balance > 1 && value < root->pLeft->data) {
            return rotateRight(root);
        }
        // RIGHT RIGHT
        if (balance < -1 && value >= root->pRight->data)
            return leftRotate(root);

        // LEFT of RIGHT
        if (balance > 1 && value >= root->pLeft->data) {
            root->pLeft = rotateLeft(root->pLeft);
            return rotateRight(root);
        }
        // RIGHT of LEFT
        if (balance < -1 && key < node->pRight->data) {
            node->pRight = rightRotate(node->pRight);
            return leftRotate(node);
        }
        return root;
    }
    void insert(const T &value) {
        // TODO
        this->root = insert(this->root, value);
    }

    class Node {
       private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

       public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};