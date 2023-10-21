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

class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it(this->terms, true);
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};


void Polynomial::insertTerm(const Term &term)
{
    if (term.coeff == 0){
        return;
    }
    int i = 0;
    SLinkedList<Term>::Iterator it(terms,true);
    for (it = this->terms->begin(); it != this->terms->end(); it++)
    {
        if (term.exp > (*it).exp)
        {
            terms->add(i,term);
            return;
        }
        else if (term.exp == (*it).exp){
            auto coeff = term.coeff + (*it).coeff;
            if (coeff == 0){
                terms->removeAt(i);
            }else {
                Term newTerm(coeff,term.exp);
                terms->set(i, newTerm);
            }
            return;
        }
        i++;
        terms->add(term);
    }
}
void Polynomial::insertTerm(double coeff, int exp)
{
    Term term(coeff, exp);
    this->insertTerm(term);
}

void Polynomial::insertTerm(const Term &term)
{
    if (term.coeff != 0)
    {
        int i = 0;
        SLinkedList<Term>::Iterator it(terms,true);
        bool termInserted = false;
        for (it = this->terms->begin(); it != this->terms->end(); it++)
        {
            if (term.exp > (*it).exp)
            {
                this->terms->add(i, term); 
                termInserted = true;
                break;
            }
            else if (term.exp == (*it).exp)
            {
                double newCoeff = term.coeff + (*it).coeff;

                if (newCoeff != 0)
                {
                    Term newTerm(newCoeff, term.exp);
                    this->terms->set(i, newTerm); 
                }
                else
                {
                    this->terms->removeAt(i); 
                }

                termInserted = true;
                break;
            }
            i++;
        }

        if (!termInserted)
        {
            this->terms->add(term);
        }
    }
}

void Polynomial::insertTerm(const Term &term)
{
    // Check if the coefficient is non-zero
    if (term.coeff != 0)
    {
        int i = 0;
        SLinkedList<Term>::Iterator it;
        bool termInserted = false; // Flag to track if the term has been inserted

        // Iterate through the list to find the correct position to insert
        for (it = this->terms->begin(); it != this->terms->end(); it++)
        {
            if (term.exp > (*it).exp)
            {
                this->terms->add(i, term); // Insert before the current element
                termInserted = true;
                break;
            }
            else if (term.exp == (*it).exp)
            {
                // If terms have the same exponent, add their coefficients
                double newCoeff = term.coeff + (*it).coeff;

                // Check if the sum of coefficients is non-zero
                if (newCoeff != 0)
                {
                    Term newTerm(newCoeff, term.exp);
                    this->terms->set(i, newTerm); // Update the current element
                }
                else
                {
                    this->terms->removeAt(i); // Remove the current element
                }

                termInserted = true;
                break;
            }
            i++;
        }

        if (!termInserted)
        {
            // If term has the lowest exponent, add it to the end of the list
            this->terms->add(term);
        }
    }
}

class LinkedList
{
public:
    class Node;

private:
    Node *head;
    Node *tail;
    int size;

public:
    class Node
    {
    private:
        int value;
        Node *next;
        friend class LinkedList;

    public:
        Node()
        {
            this->next = NULL;
        }
        Node(Node *node)
        {
            this->value = node->value;
            this->next = node->next;
        }
        Node(int value, Node *next = NULL)
        {
            this->value = value;
            this->next = next;
        }
    };
    LinkedList() : head(NULL), tail(NULL), size(0){};
    void partition(int k){
        LinkedList *Smaller = new LinkedList();
        Smaller->head = NULL;
        Smaller->tail = NULL;

        LinkedList *Equal = new LinkedList();
        Equal->head = NULL;
        Equal->tail = NULL;

        LinkedList *Larger = new LinkedList();
        Larger->head = NULL;
        Larger->tail = NULL;

        Node* temp = head;
        while (temp){
            if (temp->value <k){
                Node* newNode = new Node(k);
                if (Smaller->head == NULL){
                    Smaller->head = newNode;
                    Smaller->tail = newNode;
                }
                else{
                    Smaller->tail->next = newNode;
                    Smaller->tail = newNode; 
                }
            }else if (temp->value == k){
                Node *newNode = new Node(k);
                if (Equal->head == NULL)
                {
                    Equal->head = newNode;
                    Equal->tail = newNode;
                }
                else
                {
                    Equal->tail->next = newNode;
                    Equal->tail = newNode;
                }
            }else{
                Node *newNode = new Node(k);
                if (Larger->head == NULL)
                {
                    Larger->head = newNode;
                    Larger->tail = newNode;
                }
                else
                {
                    Larger->tail->next = newNode;
                    Larger->tail = newNode;
                }
            }
            temp = temp->next;
        }
        Smaller->tail->next = Equal->head;
        Equal->tail->next = Larger->head;
     };
};