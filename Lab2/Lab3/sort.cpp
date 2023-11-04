#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
/*
template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end)
    {
        // TODO: return the pointer which points to the pivot after rearrange the array.
        T p = start[0];
        int i = 0;
        int j = end - start;
        do
        {

            do
            {
                i++;
            } while (start[i] < p);
            do
            {
                j--;
            } while (start[j] > p);
            swap(start[i], start[j]);
        } while (i < j);
        swap(start[i], start[j]);
        swap(start[0], start[j]);
        return start + j;
    }

public:
    static void QuickSort(T *start, T *end)
    {
        // TODO
        // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
        if (start < end)
        {
            T *i = Partition(start, end);
            cout << i - start << " ";
            QuickSort(start, i);
            QuickSort(i + 1, end);
        }
    }
};
*/
template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T *left, T *middle, T *right)
    {
        /*TODO*/
        int subArrayOne = middle - left + 1;
        int subArrayTwo = right - middle;
        T *leftArray = new T[subArrayOne];
        T *rightArray = new T[subArrayTwo];

        for (int i = 0; i < subArrayOne; i++)
            leftArray[i] = left[i];
        for (int j = 0; j < subArrayTwo; j++)
            rightArray[j] = middle[j + 1];
        int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = 0;

        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {
                left[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                left[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        while (indexOfSubArrayOne < subArrayOne)
        {
            left[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            left[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        delete[] leftArray;
        delete[] rightArray;

        Sorting::printArray(left, right);
    }
    static void mergeSort(T *start, T *end)
    {
        /*TODO*/
        if (start >= end)
        {
            return;
        }
        int n = 0;
        for (auto i = start; i != end; i++)
        {
            n++;
        }
        int mid = n / 2;

        mergeSort(start, start + mid);
        mergeSort(start + mid + 1, end);
        merge(start, start + mid, end);
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val = 0, ListNode *_next = nullptr) : val(_val), next(_next) {}
};

// Merge two sorted lists
ListNode *mergeLists(ListNode *a, ListNode *b)
{
    if (a == nullptr)
    {
        return b;
    }
    if (b == nullptr)
    {
        return a;
    }
    ListNode *c;
    if (a->val < b->val)
    {
        c = a;
        c->next = mergeLists(a->next, b);
    }
    else
    {
        c = b;
        c->next = mergeLists(a, b->next);
    }
    return c;
}

ListNode *mid_point(ListNode *head)
{
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    // recursive case
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;

        if (fast->next == NULL)
            break;

        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

// Sort and unsorted list given its head pointer
ListNode *mergeSortList(ListNode *head)
{
    if (head->next == nullptr)
    {
        return head;
    }
    ListNode *mid = mid_point(head);
    ListNode *a = head;
    ListNode *b = mid->next;

    a = mergeSortList(a);
    b = mergeSortList(b);

    ListNode *c = mergeLists(a, b);

    return c;
}
int main()
{
    int arr[] = {0, 2, 4, 3, 1, 4};
    Sorting<int>::mergeSort(&arr[0], &arr[5]);

    return 0;
}