/*


class List // Singly linked list
{
public:
    int queue_size = 0;
    customer *head = NULL;
    customer *tail = NULL;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    int getSize() { return queue_size; };

    void enqueue(int energy) // Add to tail
    {
        customer *newCustomer = new customer;
        newCustomer->energy = energy;
        newCustomer->next = NULL;

        if (head == NULL)
        {
            head = newCustomer;
            tail = newCustomer;
        }
        else
        {
            tail->next = newCustomer;
            newCustomer->prev = tail;
            tail = newCustomer;
        }

        queue_size++;
    }

    void dequeue() // remove head element
    {
        if (head == NULL)
        {
            return;
        }

        customer *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        queue_size--;
    }

    void push(int energy) // Add to head
    {
        customer *newCustomer = new customer;
        newCustomer->energy = energy;
        newCustomer->prev = NULL;
        if (head == NULL)
        {
            head = newCustomer;
        }
        else
        {
            newCustomer->next = head;
            head->prev = newCustomer;
            head = newCustomer;
        }
        queue_size++;
    }

    void pop() // Same as dequeue
    {
        dequeue();
    }

    bool empty() { return !queue_size; };

    int front() // return head
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->energy;
    }

    int back() // return tail
    {
        if (tail == NULL)
        {
            return -1;
        }
        return tail->energy;
    }

    void shellSort()
    {
        // pass
    }

    customer *maxEnergyCustomer()
    {
        if (!head)
        {
            return nullptr;
        }
        int max = 0;
        customer *maxEnergy = head;
        customer *temp = tail;
        while (temp)
        {
            if (abs(temp->energy > max))
            {
                max = abs(temp->energy);
                maxEnergy = temp;
            }
            temp = temp->prev;
        }
        return maxEnergy;
    }
};

// MY Class
class List // Singly linked list
{
public:
    struct Node
    {
        customer *data;
        Node *next;
        Node *prev;
    };
    int queue_size = 0;
    Node *head = NULL;
    Node *tail = NULL;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    int getSize() { return queue_size; };

    void enqueue(customer *newCustomer) // Add to tail
    {
        Node *newNode = new Node;
        newNode->data = newCustomer;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        queue_size++;
    }

    void dequeue() // remove head element
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        queue_size--;
    }

    void push(customer *newCustomer) // Add to head
    {
        Node *newNode = new Node;
        newNode->data = newCustomer;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        queue_size++;
    }

    void pop() // Same as dequeue
    {
        dequeue();
    }

    bool empty() { return !queue_size; };

    customer *front() // return head
    {
        if (head == NULL)
        {
            return NULL;
        }
        return head->data;
    }

    customer *back() // return tail
    {
        if (tail == NULL)
        {
            return NULL;
        }
        return tail->data;
    }

    void shellSort(customer *One)
    {
        // pass
    }

    customer *maxEnergyCustomer()
    {
        if (!head)
        {
            return nullptr;
        }
        int max = 0;
        customer *maxEnergy = head->data;
        Node *temp = tail;
        while (temp)
        {
            if (abs(temp->data->energy > max))
            {
                max = abs(temp->data->energy);
                maxEnergy = temp->data;
            }
            temp = temp->prev;
        }
        return maxEnergy;
    }
};

void printCustomers()
{
    cout << "Current: " << currentCustomer->energy << endl;
    for (customer *temp = servingCustomers.front(); temp->next != NULL; temp = temp->next)
    {
        cout << temp->energy << "<->";
        if (temp->next == NULL)
        {
            cout << endl;
        }
    }
}

*/

#include <iostream>
#include <vector>
using namespace std;

// print the sorted vector
void printl(vector<int> avector)
{
    for (unsigned int i = 0; i < avector.size(); i++)
    {
        cout << avector[i] << " ";
    }
    cout << endl;
}
// function returns sorted subvector
vector<int> gapInsertionSort(vector<int> avector, int start, int gap)
{
    for (unsigned int i = start + gap; i < avector.size(); i += gap)
    {
        int currentvalue = avector[i];
        int position = i;

        while (position >= gap && avector[position - gap] > currentvalue)
        {
            avector[position] = avector[position - gap];
            position -= gap;
        }
        avector[position] = currentvalue;
    }
    return avector;
}

// function shellsorts through the vector
vector<int> shellSort(vector<int> avector)
{
    int subvectorcount = avector.size() / 2; // cuts vector by half
    while (subvectorcount > 0)
    {
        for (int startposition = 0; startposition < subvectorcount;
             startposition++)
        {
            avector = gapInsertionSort(avector, startposition, subvectorcount); /*
       runs avector through gapInsertionSort function
        */
        }
        cout << "After increments of size " << subvectorcount
             << " The vector is: " << endl;
        printl(avector);

        subvectorcount = subvectorcount / 2; // cuts vector in half
    }

    return avector;
}

int min(int a, int b)
{
    if (a >= b)
    {
        return b;
    }
    else
        return a;
}

int myMin(int arr[], int n, int k)
{
    if (n < k)
    {
        return 0;
    }
    if (n == k)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    int sum = 0;
    int min_so_far = 9999;
    int last = 0;
    int end = 3;
    int start = 0;

    int j = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    min_so_far = min(sum, min_so_far);

    for (int i = k; i < n; i++)
    {
        sum += arr[i];
        last += arr[j];
        j++;

        if (sum <= min_so_far)
        {
            end = i;
        }

        min_so_far = min(sum, min_so_far);
        if (last > 0)
        {
            sum -= last;
            min_so_far = min(sum, min_so_far);
            last = 0;
            start++;
            if (sum <= min_so_far && end - start + 1 < 4)
                end = i;
        }
    }
    return min_so_far;
}

int main()
{

    int arr[7] = {2, 1, -3, 1, 4, 1, 8};
    int arr2[8] = {-1, 2, 6, -3, -9, 10, -7, -2};
    int arr3[6] = {1, 1, -1, -1, 1, 1};
    int arr4[7] = {-9, -7, -2, -2, -7, -8, -1};

    // cout << longestMinSum(arr2, 7, 4) << endl;
    cout << myMin(arr4, 7, 4) << endl;

    // cout << start;

    return 0;
}
