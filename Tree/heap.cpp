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

static void reheapUp(T* start, long index) {
    long parent = (index - 1) / 2;

    // If index is at the root or the element is already in the correct position
    if (index <= 0 || start[index] <= start[parent]) {
        return;
    } else {
        swap(start[index], start[parent]);
        reheapUp(start, parent);
    }
}

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