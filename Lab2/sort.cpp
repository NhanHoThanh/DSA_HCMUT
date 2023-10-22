template <class T>
class Sorting
{
private:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
    // TODO: Write your code here
    static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total)
    {
        // TODO
        int size = end - start;
        int key, j;
        for (int i = 1; i * cur_segment_total + segment_idx < size; ++i)
        {
            key = start[i * cur_segment_total + segment_idx];
            j = i - 1;

            while (j >= 0 && start[j * cur_segment_total + segment_idx] > key)
            {
                start[(j + 1) * cur_segment_total + segment_idx] = start[j * cur_segment_total + segment_idx];
                j = j - 1;
            }
            start[(j + 1) * cur_segment_total + segment_idx] = key;
        }
    }
    static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases)
    {
        // TODO
        // Note: You must print out the array after sorting segments to check whether your algorithm is true.
        for (int i = num_phases - 1; i >= 0; --i)
        {
            for (int segment = 0; segment < num_segment_list[i]; ++segment)
            {
                sortSegment(start, end, segment, num_segment_list[i]);
            }
            cout << num_segment_list[i] << " segments: ";
            printArray(start, end);
        }
    }

    static void selectionSort(T *start, T *end);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    for (T *i = start; i != end - 1; i++)
    {
        T *min_idx = i;
        for (T *j = i + 1; j != end; j++)
        {
            if (*j < *min_idx)
            {
                min_idx = j;
            }
        }
        swap(*i, *min_idx);
        printArray(start, end);
    }
}

#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class SLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
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
        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort();
};

template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (this->count == 0 || this->count == 1)
        return;
    Node *unsorted = this->head;
    Node *sorted = this->tail->next;
    Node *sentinel = sorted;
    bool isSwapped = true;

    while (isSwapped)
    {
        sentinel = sorted;
        isSwapped = false;
        unsorted = this->head;
        while (unsorted->next != sorted)
        {
            if (unsorted->data > unsorted->next->data)
            {
                T temp = unsorted->data;
                unsorted->data = unsorted->next->data;
                unsorted->next->data = temp;
                isSwapped = true;
            }
            unsorted = unsorted->next;
        }

        sorted = this->head;
        while (sorted->next != sentinel)
            sorted = sorted->next;
        if (isSwapped)
            this->printList();
    }
}