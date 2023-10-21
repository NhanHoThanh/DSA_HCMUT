#include <bits/stdc++.h>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Iterator; // forward declaration
    class Node;     // forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();

        // Prefix ++ overload
        Iterator &operator++();

        // Postfix ++ overload
        Iterator operator++(int);
    };
};

/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin)
{
    this->pList = pList;
    if (begin)
    {
        if (pList != NULL)
        {
            this->current = pList->head;
            index = 0;
        }
        else
        {
            this->current = nullptr;
            index = -1;
        }
    }
    else
    {
        this->current = nullptr;
        if (pList != NULL)
        {
            index = pList->size();
        }
        else
        {
            index = 0;
        }
    }
}

template <class T>
typename DLinkedList<T>::Iterator &DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T>
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current == NULL)
    {
        throw std::out_of_range("Segmentation fault!");
    }
    else
    {
        current->data = e;
    }
}

template <class T>
T &DLinkedList<T>::Iterator::operator*()
{
    if (current == NULL)
    {

        throw std::out_of_range("Segmentation fault!");
    }
    else
    {
        return current->data;
    }
}

template <class T>
void DLinkedList<T>::Iterator::remove()
{
    /*
     * TODO: delete Node in pList which Node* current point to.
     *       After that, Node* current point to the node before the node just deleted.
     *       If we remove first node of pList, Node* current point to nullptr.
     *       Then we use operator ++, Node* current will point to the head of pList.
     */
    if (current == nullptr)
    {
        return;
    }

    Node *nodeToRemove = current;
    current = current->previous;

    if (current != nullptr)
    {
        current->next = nodeToRemove->next;
    }
    else
    {
        pList->head = nodeToRemove->next;
    }

    if (nodeToRemove->next != nullptr)
    {
        nodeToRemove->next->previous = current;
    }
    else
    {
        pList->tail = current;
    }

    delete nodeToRemove;
    pList->count--;
}

template <class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator)
{
    if (this->pList == iterator.pList && this->current == iterator.current && this->index == iterator.index)
        return false;
    return true;
}

template <class T>
typename DLinkedList<T>::Iterator &DLinkedList<T>::Iterator::operator++()
{
    current = current->next;
    if (current == nullptr)
    {
        current = pList->head;
    }
    index++;
    return *this;
}

template <class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    current = current->next;
    if (current == nullptr)
    {
        current = pList->head;
    }
    if (current == nullptr)
    {
        throw std::out_of_range("Segmentation fault!");
    }
    return temp;
}

int main()
{
    DLinkedList<int> list;
    int size = 10;
    for (int idx = 0; idx < size; idx++)
    {
        list.add(idx);
    }
    DLinkedList<int>::Iterator it = list.begin();
    for (; it != list.end(); it++)
    {
        cout << *it << " |";
    }
}