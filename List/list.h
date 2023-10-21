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
    Array();
    Array(int capacity);
    ~Array();
    void insertHead(T element);
    void insertTail(T element);
    void insert(int index, T element);
    void removeAt(int index);
    bool removeItem(T item);
    bool empty();
    int size()
    {
        return count;
    };
    T get(int index);
    void set(int index, T element);
    int indexOf(T item);
    bool contains(T item);
    void clear();
    void printList();
    Array<T> &operator=(const Array<T> &other)
};