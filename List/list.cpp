#include <bits/stdc++.h>
#include <string.h>

using namespace std;

template <typename T>
class List
{
public:
    virtual void insertHead(T element) = 0;
    virtual void insertTail(T element) = 0;
    virtual void insert(int index, T element) = 0;
    virtual void removeAt(int index) = 0;
    virtual bool removeItem(T item) = 0;
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual T get(int index) = 0;
    virtual void set(int index, T element) = 0;
    virtual int indexOf(T item) = 0;
    virtual bool contains(T item) = 0;
    virtual void clear() = 0;
    virtual void printList() = 0;
    // virtual void forEach() = 0;
};

template <typename T>
class Array : public List<T>
{
private:
    int capacity;
    int count;
    T *array;

    int initialCapacity = 10;

public:
    Array()
    {
        this->capacity = initialCapacity;
        this->count = 0;
        this->array = new T[capacity];
    }
    Array(int capacity) : capacity(capacity), count(0)
    {
        int initialSize = capacity / this->initialCapacity + (capacity % this->initialCapacity != 0);
        array = new T[initialSize * this->initialCapacity];
    }
    ~Array()
    {
        delete array;
        count = 0;
        capacity = 0;
    }
    void insertHead(T element)
    {
        if (count == capacity)
        {
            capacity *= 2;
            T *newArray = new T[capacity];
            for (int i = 0; i < count; ++i)
            {
                newArray[i + 1] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        else
        {
            for (int i = count; i > 0; i--)
            {
                array[i] = array[i - 1];
            }
        }

        array[0] = element;
        ++count;
    }
    void insertTail(T element)
    {
        if (count == capacity)
        {
            capacity *= 2;
            T *newArray = new T[capacity];
            for (int i = 0; i < count; ++i)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }

        array[count++] = element;
    }

    void insert(int index, T element)
    {
        if (index < 0)
        {
            insertHead(element);
            return;
        }
        else if (index > count)
        {
            index = count;
        }

        if (count == capacity)
        {
            capacity *= 2;
            T *newArray = new T[capacity];
            for (int i = 0; i < count; ++i)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }

        for (int i = count; i > index; --i)
        {
            array[i] = array[i - 1];
        }

        array[index] = element;
        ++count;
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Index out of range");
        }

        for (int i = index; i < count - 1; ++i)
        {
            array[i] = array[i + 1];
        }

        --count;
    }

    bool removeItem(T item)
    {
        int index = indexOf(item);
        if (index != -1)
        {
            removeAt(index);
            return true;
        }
        return false;
    }

    bool empty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }

    T get(int index)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    void set(int index, T element)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Index out of range");
        }
        array[index] = element;
    }

    int indexOf(T item)
    {
        for (int i = 0; i < count; ++i)
        {
            if (array[i] == item)
            {
                return i;
            }
        }
        return -1;
    }

    bool contains(T item)
    {
        return indexOf(item) != -1;
    }

    void clear()
    {
        delete[] array;
        array = new T[initialCapacity];
        capacity = initialCapacity;
        count = 0;
    }
    Array<T> &operator=(const Array<T> &other)
    {
        if (this != &other)
        {
            delete[] array;
            capacity = other.capacity;
            count = other.count;
            array = new T[capacity];
            for (int i = 0; i < count; i++)
            {
                array[i] = other.array[i];
            }
        }
        return *this;
    }
    void printList()
    {
        for (int i = 0; i < count; i++)
        {
            cout << array[i] << endl;
        }
    }
};

template <typename T>
class LinkedList : public List<T>
{
public:
    class Node
    {
    public:
        T data;
        Node *next;

    public:
        Node() : next(NULL){};
        Node(T data) : data(data), next(NULL){};
        Node(T value, Node *nextNode) : data(value), next(nextNode) {}
    };

private:
    Node *head;
    Node *tail;
    int count;

public:
    LinkedList() : head(NULL), tail(NULL), count(0){};

    void insertHead(T element)
    {
        Node *temp = new Node(element);
        temp->next = head->next;
        head = temp;
        count++;
    }
    void insertTail(T element)
    {
        Node *tmp = new Node(element);
        if (head == nullptr)
        {
            count = 1;
            head = tmp;
            tail = tmp;
            tmp->next = nullptr;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
            count++;
        }
    }

    void insert(int index, T element)
    {
        if (index >= count)
        {
            insertTail(element);
            return;
        }
        if (index <= 0)
        {
            insertHead(element);
            return;
        }
        Node *prev = head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        Node *tmp = new Node(element);
        tmp->next = prev->next;
        prev->next = tmp;
    }
    void teacherInsert(int idx, T value)
    {
        if (idx < 0)
        {
            idx = 0;
        }
        else if (idx > count)
        {
            idx = count;
        }
        Node **p = &head;
        while (idx && *p)
        {
            p = &((*p)->next);
            idx--;
        }
        *p = new Node(value);
        count++;
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            --count;
            return;
        }
        Node *tmp = head;
        for (int i = 0; i < index - 1; i++)
        {
            tmp = tmp->next;
        }
        Node *deleteNode = tmp->next;
        tmp->next = deleteNode->next;
        delete deleteNode;
    }

    bool removeItem(T item)
    {
        Node *tmp = head;
        int n = indexOf(item);
        if (n)
        {
            removeAt(n);
        }
        else
            return false;
    }

    bool empty()
    {
        bool something = count;
        return !something;
    }

    int size()
    {
        return count;
    }

    T get(int index)
    {
        Node *tmp = head;

        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    void set(int index, T element)
    {
        Node *tmp = head;

        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
        tmp->data = element;
    }

    int indexOf(T item)
    {
        Node *tmp = head;
        int index = 0;
        for (int i = 0; i < size(); i++)
        {
            if (tmp->data == item)
            {
                return index;
            }
            tmp = tmp->next;
        }
        return -1;
    }

    bool contains(T item)
    {
        return indexOf(item) != -1;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        count = 0;
    }
    void forEach(std::function<void(T &)> func)
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            func(tmp->data);
            tmp = tmp->next;
        }
    }
    LinkedList<T> &operator=(const LinkedList<T> &other)
    {
        if (this != &other)
        {
            clear();
            Node *temp = other.head;
            while (temp != nullptr)
            {
                insertTail(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }
    void printList()
    {
        Node *temp = head;
        for (int i = 0; i < this->size(); i++)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

template <typename T>
class Stack : public Array<T>
{
public:
    Stack() : Array<T>(){};
    Stack(int capacity) : Array<T>(capacity){};
    void push(T element)
    {
        Array<T>::insertTail(element);
    }
    T pop()
    {
        T temp = Array<T>::get(Array<T>::size() - 1);
        Array<T>::removeAt(Array<T>::size() - 1);
        return temp;
    }
    T top()
    {
        return Array<T>::get(Array<T>::size() - 1);
    }
    bool empty()
    {
        return Array<T>::size() == 0;
    }
    int size()
    {
        return this->size();
    }
    void clear()
    {
        Array<T>::clear();
    }
    void printList()
    {
        this->printList();
    }
    Stack<T> &operator=(Stack<T> &other)
    {
        if (this != &other)
        {
            this.clear();
            for (int i = 0; i < other.size(); i++)
            {
                this.insertTail(other.array.get(i));
            }
        }
        return *this;
    }
};

class Person // example for an array and a linked list that can hold class
{
private:
    string name;
    int age;
    string sex;

public:
    Person()
    {
        this->name = "";
        this->age = 0;
        this->sex = "N/A";
    };
    Person(string name, int age, string sex) : name(name), age(age), sex(sex) {}

    string getName()
    {
        return this->name;
    }
    int getAge()
    {
        return this->age;
    }
    string getGender()
    {
        return this->sex;
    }
    void showInfo()
    {
        cout << getName() << " " << getAge() << " " << getGender() << endl;
    }
    bool operator==(Person &other)
    {
        return this->age == other.getAge() && this->name == other.getName() && this->sex == other.getGender();
    }
};

ostream &operator<<(ostream &out, Person &person) // overload the operator for the printList() function
{
    out << person.getAge() << " " << person.getName() << " " << person.getGender();
    return out;
};

// Double Linked List
/*
template <typename T>
class DoubleLinkedList : public List<T>
{
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *prev;

    public:
        Node() : next(NULL), prev(NULL){};
        Node(T data) : data(data), next(NULL), prev(NULL){};
    };

private:
    Node *head;
    Node *tail;
    int count;

public:
    DoubleLinkedList() : head(NULL), tail(NULL), count(0){};
    void insertHead(T element)
    {
        Node *temp = new Node(element);
        temp->next = head->next;
        temp->prev = nullptr;
        head = temp;
    }
    void insertTail(T data)
    {
        Node *temp = new Node(element);
        temp->next = nullptr;
        temp->prev = tail->prev;
        tail = temp;
    }
};
*/
int main()
{
    Stack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << "Stack size: " << stack.size() << std::endl;
    // std::cout << "Stack top: " << stack.top() << std::endl;

    // stack.pop();
    // stack.pop();

    // std::cout << "Stack size: " << stack.size() << std::endl;
    // std::cout << "Stack top: " << stack.top() << std::endl;

    // stack.clear();
    // std::cout << "Stack size after clear: " << stack.size() << std::endl;
    // return 0;
}
/*
LinkedList<Person> personList; // Create a linked list of Persons
Array<Person> personArray;     // Create an array of Persons

// Create three Person objects
Person person1("John Doe", 30, "Male");
Person person2("Jane Doe", 25, "Female");
Person person3("Bob Smith", 35, "Male");

// Add persons to linked list
personList.teacherInsert(0, person1);
personList.teacherInsert(1, person2);
personList.teacherInsert(2, person3);

// Print persons from linked list
cout << "Persons in Linked List:" << endl;
personList.printList();
cout << endl;
personList.forEach([](Person &person) -> void
               { person = Person(person.getName(), person.getAge() + 1, person.getGender()); });

personList.forEach([](Person &person) -> void
               { person.showInfo(); });
// Print persons from array
cout << "Persons in Array:" << endl;
personArray.printList();

return 0;
*/

// Author: NhanHoTHanh
/*Missing fuction
tranverse: go thought the list and do something (not exacty print it out, maybe add a value)
tranverse(con tro ham) for both array and linkedlist
find more about std::function and std::move
you should master the pointer
*/
