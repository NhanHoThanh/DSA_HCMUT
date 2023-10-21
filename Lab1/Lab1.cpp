#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class SLinkedList
{
public:
    class Iterator; // forward declaration
    class Node;     // forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};

    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);

    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
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
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        void remove();
        T &operator*();
        bool operator!=(const Iterator &iterator);

        // Prefix ++ overload
        Iterator &operator++();

        // Postfix ++ overload
        Iterator operator++(int);
    };
};

template <class T>
void SLinkedList<T>::add(const T &e)
{
    /* Insert an element into the end of the list. */
    Node *newNode = new Node(e);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
    /* Insert an element into the list at given index. */
    if (index < 0 || index > count)
    {
        throw std::out_of_range("Index out of range");
    }
    if (index == count)
    {
        add(e);
        return;
    }
    Node *newNode = new Node(e);
    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *prev = head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    count++;
}

template <class T>
int SLinkedList<T>::size()
{
    /* Return the length (size) of list */
    return count;
}
template <class T>
T SLinkedList<T>::get(int index)
{
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index >= count)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T &e)
{
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= count)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    current->data = e;
}

template <class T>
bool SLinkedList<T>::empty()
{
    /* Check if the list is empty or not. */
    return count == 0;
}

template <class T>
int SLinkedList<T>::indexOf(const T &item)
{
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node *current = head;
    for (int i = 0; i < count; i++)
    {
        if (current->data == item)
        {
            return i;
        }
        current = current->next;
    }
    return -1;
}

template <class T>
bool SLinkedList<T>::contains(const T &item)
{
    /* Check if item appears in the list */
    return indexOf(item) != -1;
}
template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    Node *prev = NULL;
    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }
    T removedValue = current->data;
    if (prev == NULL)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    if (current == tail)
    {
        tail = prev;
    }
    delete current;
    count--;
    return removedValue;
}

template <class T>
bool SLinkedList<T>::removeItem(const T &item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL)
    {
        if (current->data == item)
        {
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            if (current == tail)
            {
                tail = prev;
            }
            delete current;
            count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

template <class T>
void SLinkedList<T>::clear()
{
    /* Remove all elements in list */
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}

template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T> *pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true:
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false:
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
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
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
    if (current == NULL)
    {
        throw std::out_of_range("Segmentation fault!");
    }
    else if (current == pList->head)
    {
        delete current;
        current = nullptr;
        index = -1;
    }
    else
    {
        Node *prev = current;
        while (prev != current)
        {
            prev = prev->next;
        }
        prev->next = current->next;
        delete current;
        current = prev;
        index--;
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
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
T &SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
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
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
    return (this->index != iterator.index || this->current->data != iterator.current->data);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head

        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end

    */
    current = current->next;
    if (current == nullptr)
    {
        current = pList->head;
    }

    index++;
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    // Save the current iterator
    // Save the current iterator value
    Iterator temp = *this;

    // Move the iterator to the next node
    current = current->next;

    // If the iterator corresponds to the previous "node" of head, set it to head
    if (current == nullptr)
    {
        current = pList->head;
    }

    // If the iterator corresponds to the end, throw an exception
    if (current == nullptr)
    {
        throw std::out_of_range("Segmentation fault!");
    }

    // Return the saved iterator value
    return temp;
}

class Polynomial;
class Term
{
private:
    double coeff;
    int exp;
    friend class Polynomial;

public:
    Term(double coeff = 0.0, int exp = 0)
    {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term &rhs) const
    {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream &operator<<(ostream &os, const Term &term)
    {
        cout << endl;
        cout << "Term: "
             << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial
{
private:
    SLinkedList<Term> *terms;

public:
    Polynomial()
    {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial()
    {
        this->terms->clear();
    }
    void insertTerm(const Term &term);
    void insertTerm(double coeff, int exp);
    void print()
    {
        SLinkedList<Term>::Iterator it(terms, true);
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++)
        {
            cout << (*it);
        }
        cout << endl
             << "]";
    }
};

void Polynomial::insertTerm(const Term &term)
{
    // STUDENT ANSWER
}

void Polynomial::insertTerm(double coeff, int exp)
{
    // STUDENT ANSWER
}

int main()
{

    SLinkedList<int> list;

    int size = 10;
    for (int idx = 0; idx < size; idx++)
    {
        list.add(idx);
        cout << list.size() << " " << list.get(idx) << endl;
    }
    SLinkedList<int>::Iterator it(&list, true);
    int expvalue = 0;
    for (it = list.begin(); it != list.end(); it++)
    {

        assert(*it == expvalue);
        if (*it == expvalue)
        {
            cout << "evaluated" << endl;
        }

        cout << "it: " << *it << ", expvalue: " << expvalue << std::endl;
        expvalue += 1;
    }
    cout << "true";
    return 0;
}