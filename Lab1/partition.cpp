#include <iostream>
using namespace std;
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
    void LinkedList :: partition(int k)
    {
        LinkedList *Smaller = new LinkedList();
        Smaller->head = NULL;
        Smaller->tail = NULL;

        LinkedList *Equal = new LinkedList();
        Equal->head = NULL;
        Equal->tail = NULL;

        LinkedList *Larger = new LinkedList();
        Larger->head = NULL;
        Larger->tail = NULL;

        Node *temp = head;
        while (temp)
        {
            if (temp->value < k)
            {
                Node *newNode = new Node(temp->value);
                if (Smaller->head == NULL)
                {
                    Smaller->head = newNode;
                    Smaller->tail = newNode;
                }
                else
                {
                    Smaller->tail->next = newNode;
                    Smaller->tail = newNode;
                }
            }
            else if (temp->value == k)
            {
                Node *newNode = new Node(temp->value);
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
            }
            else
            {
                Node *newNode = new Node(temp->value);
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
        if (Smaller->head != nullptr && Equal->head != nullptr && Larger->head != nullptr)
        {
            Smaller->tail->next = Equal->head;
            Equal->tail->next = Larger->head;
            head = Smaller->head;
            tail = Larger->tail;
        }
        else if (Smaller->head == nullptr && Equal->head != nullptr && Larger->head != nullptr)
        {
            Equal->tail->next = Larger->head;
            head = Equal->head;
            tail = Larger->tail;
        }
        else if (Smaller->head != nullptr && Equal->head == nullptr && Larger->head != nullptr)
        {
            Smaller->tail->next = Larger->head;
            head = Smaller->head;
            tail = Larger->tail;
        }
        else if (Smaller->head != nullptr && Equal->head != nullptr && Larger->head == nullptr)
        {
            Smaller->tail->next = Equal->head;
            head = Smaller->head;
            tail = Equal->tail;
        }
        else if (Smaller->head == nullptr && Equal->head == nullptr && Larger->head != nullptr)
        {
            head = Larger->head;
            tail = Larger->tail;
        }
        else
        {
            head = tail = nullptr;
        }
    };
};

void LinkedList :: partition(int k)
{
    LinkedList *Smaller = new LinkedList();
    LinkedList *Equal = new LinkedList();
    LinkedList *Larger = new LinkedList();

    Node *temp = head;

    while (temp)
    {
        Node *newNode = new Node(temp->value);

        if (temp->value < k)
        {
            Smaller->append(newNode);
        }
        else if (temp->value == k)
        {
            Equal->append(newNode);
        }
        else
        {
            Larger->append(newNode);
        }

        temp = temp->next;
    }

    if (Smaller->head != nullptr)
    {
        Smaller->tail->next = Equal->head != nullptr ? Equal->head : Larger->head;
        head = Smaller->head;
        tail = Larger->head != nullptr ? Larger->tail : Equal->tail;
    }
    else if (Equal->head != nullptr)
    {
        Equal->tail->next = Larger->head;
        head = Equal->head;
        tail = Larger->head != nullptr ? Larger->tail : Equal->tail;
    }
    else if (Larger->head != nullptr)
    {
        head = Larger->head;
        tail = Larger->tail;
    }
    else
    {
        head = tail = nullptr;
    }

    delete Smaller;
    delete Equal;
    delete Larger;
}

void LinkedList:: partition(int k)
{
    LinkedList *Smaller = new LinkedList();
    LinkedList *Equal = new LinkedList();
    LinkedList *Larger = new LinkedList();

    Node *temp = head;

    while (temp)
    {
        Node *newNode = new Node(temp->value);

        if (temp->value < k)
        {
            if (Smaller->tail == nullptr)
            {
                Smaller->head = Smaller->tail = newNode;
            }
            else
            {
                Smaller->tail->next = newNode;
                Smaller->tail = newNode;
            }
        }
        else if (temp->value == k)
        {
            if (Equal->tail == nullptr)
            {
                Equal->head = Equal->tail = newNode;
            }
            else
            {
                Equal->tail->next = newNode;
                Equal->tail = newNode;
            }
        }
        else
        {
            if (Larger->tail == nullptr)
            {
                Larger->head = Larger->tail = newNode;
            }
            else
            {
                Larger->tail->next = newNode;
                Larger->tail = newNode;
            }
        }

        temp = temp->next;
    }

    if (Smaller->head != nullptr)
    {
        Smaller->tail->next = Equal->head != nullptr ? Equal->head : Larger->head;
        head = Smaller->head;
        tail = Larger->head != nullptr ? Larger->tail : Equal->tail;
    }
    else if (Equal->head != nullptr)
    {
        Equal->tail->next = Larger->head;
        head = Equal->head;
        tail = Larger->head != nullptr ? Larger->tail : Equal->tail;
    }
    else if (Larger->head != nullptr)
    {
        head = Larger->head;
        tail = Larger->tail;
    }
    else
    {
        head = tail = nullptr;
    }

    delete Smaller;
    delete Equal;
    delete Larger;
}

int main()
{
    LinkedList *l1 = new LinkedList();
    l1->add(20);
    l1->add(30);
    l1->add(10);
    l1->add(60);
    l1->add(40);
    l1->add(45);
    l1->add(55);
    l1->partition(45);
    cout << l1->toString() << "\n";
}