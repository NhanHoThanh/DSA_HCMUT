// write your helper functions here
void rotateRight(Node* node) {
    Node* T = node->pLeft;
    Node* B = T->pRight;
    Node* D = node->pParent;
    if (D) {
        if (D->pRight == node)
            D->pRight = T;
        else
            D->pLeft = T;
    }
    if (B) {
        B->pParent = node;
    }
    T->pParent = D;
    T->pRight = node;
    node->pParent = T;
    node->pLeft = B;
}
void rotateLeft(Node* node) {
    Node* T = node->pRight;
    Node* B = T->pLeft;
    Node* D = node->pParent;
    if (D) {
        if (D->pRight == node)
            D->pRight = T;
        else
            D->pLeft = T;
    }
    if (B) {
        B->pParent = node;
    }
    T->pParent = D;
    T->pLeft = node;
    node->pParent = T;
    node->pRight = B;
}

void splay(Node* p) {
    while (p->pParent) {
        Node* parent = p->pParent;
        Node* grandparent = parent->pParent;
        if (grandparent == nullptr) {
            // Zig step
            if (p == parent->pLeft)
                rotateRight(parent);
            else
                rotateLeft(parent);
            parent = p->pParent;
        } else {
            if (p == parent->pLeft && parent == grandparent->pLeft) {
                // Zig-zig step
                rotateRight(grandparent);
                parent = p->pParent;
                rotateRight(parent);
                parent = p->pParent;
            } else if (p == parent->pRight && parent == grandparent->pRight) {
                // Zig-zig step
                rotateLeft(grandparent);
                parent = p->pParent;
                rotateLeft(parent);
                parent = p->pParent;
            } else {
                // Zig-zag step
                if (p == parent->pLeft)
                    rotateRight(parent);
                else
                    rotateLeft(parent);
                parent = p->pParent;
                if (p == parent->pLeft)
                    rotateRight(parent);
                else
                    rotateLeft(parent);
                parent = p->pParent;
            }
        }
    }
    root = p;
}
void insert(int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    Node* currentNode = root;
    Node* parent = nullptr;
    while (currentNode) {
        parent = currentNode;
        if (val < currentNode->val)
            currentNode = currentNode->pLeft;
        else
            currentNode = currentNode->pRight;
    }
    Node* newNode = new Node(val, nullptr, nullptr, parent);
    if (val < parent->val)
        parent->pLeft = newNode;
    else
        parent->pRight = newNode;
    splay(newNode);
}
bool searchRec(int val, Node*& node, Node*& par) {
    if (node == nullptr) {
        if (par) splay(par);
        return false;
    }
    if (val < node->val) return searchRec(val, node->pLeft, node);
    if (val > node->val) return searchRec(val, node->pRight, node);
    splay(node);
    return true;
}
bool search(int val) {
    if (root == nullptr) return false;
    return searchRec(val, root, root->pParent);
    // To Do
}
Node* remove(int val) {
    // TODO
    if (root == nullptr) return nullptr;
    search(val);
    if (root->val == val) {
        if (!root->pLeft) {
            Node* tmp = root;
            root = root->pRight;
            if (root) root->pParent = nullptr;
            return tmp;
        }
        Node* treeL = root->pLeft;
        Node* treeR = root->pRight;
        treeL->pParent = nullptr;
        root->pLeft = root->pRight = nullptr;
        Node* ans = root;
        while (treeL->pRight) treeL = treeL->pRight;
        splay(treeL);
        treeL->pRight = treeR;
        if (treeR) treeR->pParent = treeL;
        return ans;
    }
    return nullptr;
    // To Do
}