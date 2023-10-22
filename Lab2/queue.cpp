#include <bits/stdc++.h>
using namespace std;

// For the queue implementation
/*
void push(T item)
{
    // TODO: Push new element into the end of the queue
    this->list.add(item);
}

T pop()
{
    // TODO: Remove an element in the head of the queue
    if (this->empty())
        throw std::out_of_range("Empty Queue");
    return this->list.removeAt(0);
}

T top()
{
    // TODO: Get value of the element in the head of the queue
    if (this->empty())
        throw std::out_of_range("Empty Queue");
    return this->list.get(0);
}

bool empty()
{
    // TODO: Determine if the queue is empty
    return this->list.empty();
}

int size()
{
    // TODO: Get the size of the queue
    return this->list.size();
}

void clear()
{
    // TODO: Clear all elements of the queue
    return this->list.clear();
}

*/

bool isBipartite(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (color[i] != 0)
            continue;
        color[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto &x : graph[t])
            {
                if (color[x] == 0)
                {
                    color[x] = -color[t];
                    q.push(x);
                }
                else if (color[x] == color[t])
                    return false;
            }
        }
    }
    return true;
}

void interleaveQueue(queue<int> &q)
{
    queue<int> st1;
    queue<int> st2;
    int n = q.size();
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        st1.push(q.front());
        q.pop();
    }
    for (int i = mid; i < n; i++)
    {
        st2.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            q.push(st1.front());
            st1.pop();
        }
        else
        {
            q.push(st2.front());
            st2.pop();
        }
    }
}

long long nthNiceNumber(int n)
{
    queue<long long> q;
    q.push(2);
    q.push(5);
    while (--n)
    {
        long long x = q.front();
        q.pop();
        q.push(x * 10 + 2);
        q.push(x * 10 + 5);
    }
    return q.front();
}

int sumOfMaxSubarray(vector<int> &nums, int k)
{
    // STUDENT ANSWER
    int n = nums.size();
    int sum = 0;
    int max = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
        cout << sum << endl;
    }
    for (int i = k; i < n; i++)
    {
        int temp = sum - nums[i - k] + nums[i];
        if (temp > sum)
        {
            max = temp;
            cout << max << endl;
        }
        sum = temp;
    }
    return max;
}

int main()
{
    vector<int> nums{1, 2, 4, 3, 6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k);
    return 0;
}