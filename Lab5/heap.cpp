// Cau 1
template <class T>
int Heap<T>::size() {
    return this->count;
}

template <class T>
bool Heap<T>::isEmpty() {
    return !count;
}

template <class T>
T Heap<T>::peek() {
    if (isEmpty()) return -1;
    return elements[0];
}

template <class T>
bool Heap<T>::contains(T item) {
    if (isEmpty()) return false;
    for (int i = 0; i < count; i++) {
        if (elements[i] == item) return true;
    }
    return false;
}

template <class T>
bool Heap<T>::pop() {
    if (isEmpty()) return false;
    elements[0] = elements[count - 1];
    count--;
    reheapDown(0);
    return true;
}

// Cau 2
template <class T>
void Heap<T>::push(T item) {
    if (count == capacity) ensureCapacity(capacity * 2);
    elements[count] = item;
    count++;
    reheapUp(count - 1);
}

template <class T>
void Heap<T>::ensureCapacity(int minCapacity) {
    T* newElements = new T[minCapacity];
    for (int i = 0; i < count; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = minCapacity;
}

template <class T>
void Heap<T>::reheapUp(int position) {
    while (position > 0) {
        int parent = (position - 1) / 2;
        if (elements[position] > elements[parent]) {
            T temp = elements[position];
            elements[position] = elements[parent];
            elements[parent] = temp;
            position = parent;
        } else
            break;
    }
}
// Cau 3
void reheapDown(int elements[], int count, int node) {
    int leftChild = node * 2 + 1;
    int rightChild = node * 2 + 2;
    int lastUsed = count - 1;
    if (leftChild <= lastUsed) {
        int largest = leftChild;
        if (rightChild <= lastUsed && elements[largest] < elements[rightChild]) {
            largest = rightChild;
        }
        if (elements[node] < elements[largest]) {
            int temp = elements[node];
            elements[node] = elements[largest];
            elements[largest] = temp;
            reheapDown(elements, count, largest);
        }
    }
}

void reheapUp(int elements[], int numberOfElements, int position) {
    while (position > 0) {
        int parent = (position - 1) / 2;
        if (elements[position] > elements[parent]) {
            int temp = elements[position];
            elements[position] = elements[parent];
            elements[parent] = temp;
            position = parent;
        } else
            break;
    }
}
// Cau 4
template <class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    if (this->count == 0) return -1;
    for (int i = 0; i < this->count; ++i) {
        if (this->elements[i] == item) return i;
    }
    return -1;
}

template <class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    if (index == -1) {
        return;
    }

    elements[index] = elements[count - 1];
    count--;

    // Reheapify the heap
    reheapDown(index);
    reheapUp(index);
}

template <class T>
void Heap<T>::clear() {
    delete[] elements;
    capacity = 10;
    count = 0;
    elements = new T[capacity];
}

// Heap Sort
static void heapify(T* arr, long size, long index) {
    long largest = index;
    long left = 2 * index + 1;
    long right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

static void heapSort(T* start, T* end) {
    long size = end - start;

    for (long i = size / 2 - 1; i >= 0; i--)
        heapify(start, size, i);

    for (long i = size - 1; i > 0; i--) {
        swap(start[0], start[i]);
        heapify(start, i, 0);
    }

    Sorting<T>::printArray(start, end);
}
// Cau 6
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
   public:
    int priority;
    string fileName;
    int timestamp;

    Node(int p, string f, int t) : priority(p), fileName(f), timestamp(t) {}

    // Overload the < operator for comparison in priority_queue
    bool operator<(const Node& n) const {
        if (priority == n.priority) {
            return timestamp > n.timestamp;
        }
        return priority < n.priority;
    }
};

class PrinterQueue {
    priority_queue<Node> pq;
    int time = 0;

   public:
    void addNewRequest(int priority, string fileName) {
        pq.push(Node(priority, fileName, time++));
    }

    void print() {
        if (pq.empty()) {
            cout << "No file to print" << endl;
        } else {
            Node top = pq.top();
            pq.pop();
            cout << top.fileName << endl;
        }
    }
};

// Cau 7
int leastAfter(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    while (k-- > 0) {
        int x = pq.top();
        pq.pop();
        pq.push(x * 2);
    }
    return pq.top();
}