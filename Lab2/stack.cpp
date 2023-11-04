#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

template <class T>
class DLinkedList
{
public:
    class Node; // forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList();
    ~DLinkedList();
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
};

template <class T>
class Stack
{
protected:
    DLinkedList<T> list;

public:
    Stack() {}
    void push(T item)
    {
        // TODO: Push new element into the top of the stack
        this->list.add(0, item);
    }

    T pop()
    {
        // TODO: Remove an element on top of the stack
        if (this->list.empty())
            throw std::out_of_range("Stack Underflow");
        return this->list.removeAt(0);
    }

    T top()
    {
        // TODO: Get value of the element on top of the stack
        if (this->list.empty())
            throw std::out_of_range("Stack Underflow");
        return this->list.get(0);
    }

    bool empty()
    {
        // TODO: Determine if the stack is empty
        return this->list.empty();
    }

    int size()
    {
        // TODO: Get the size of the stack
        return this->list.size();
    }

    void clear()
    {
        // TODO: Clear all elements of the stack
        this->list.clear();
    }
};

// iostream, stack and vector are included

vector<int> nextGreater(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                arr[i] = arr[j];
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        else
        {
            arr[i] = -1;
        }
    }
    arr[n] = -1;
    return arr;
}

#include <sstream> //for the evaluatePostfix

int evaluatePostfix(string expr)
{
    stack<int> result;

    std::string str = expr;
    std::stringstream ss(str);

    std::string token;
    while (ss >> token)
    {
        string s = token;
        if (s == "*")
        {
            int x1 = result.top();
            result.pop();
            int x2 = result.top();
            result.pop();
            result.push(x1 * x2);
        }
        else if (s == "+")
        {
            int x1 = result.top();
            result.pop();
            int x2 = result.top();
            result.pop();
            result.push(x1 + x2);
        }
        else if (s == "/")
        {
            int x1 = result.top();
            result.pop();
            int x2 = result.top();
            result.pop();
            if (x1 != 0)
            {
                result.push(x2 / x1);
            }
            else
            {
                // Handle division by zero
                return -1; // You might want to return an error code or throw an exception
            }
        }
        else if (s == "-")
        {
            int x1 = result.top();
            result.pop();
            int x2 = result.top();
            result.pop();
            result.push(x2 - x1);
        }
        else
        {
            int temp = stoi(s);
            result.push(temp);
        }
    }
    return result.top();
}

class node
{
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;

        // Initially direction
        // set to 0
        dir = 0;
    }
};

bool canEatFood(int maze[5][5], int fx, int fy)
{
    int n = 5;
    int m = 5;

    bool visited[5][5];
    memset(visited, true, sizeof(visited));

    // Initially starting at (0, 0).
    int i = 0, j = 0;

    stack<node> s;

    node temp(i, j);

    s.push(temp);

    while (!s.empty())
    {

        // Pop the top node and move to the
        // left, right, top, down or retract
        // back according the value of node's
        // dir variable.
        temp = s.top();
        int d = temp.dir;
        i = temp.x, j = temp.y;

        // Increment the direction and
        // push the node in the stack again.
        temp.dir++;
        s.pop();
        s.push(temp);

        // If we reach the Food coordinates
        // return true
        if (i == fx and j == fy)
        {
            return true;
        }

        // Checking the Up direction.
        if (d == 0)
        {
            if (i - 1 >= 0 and maze[i - 1][j] and
                visited[i - 1][j])
            {
                node temp1(i - 1, j);
                visited[i - 1][j] = false;
                s.push(temp1);
            }
        }

        // Checking the left direction
        else if (d == 1)
        {
            if (j - 1 >= 0 and maze[i][j - 1] and
                visited[i][j - 1])
            {
                node temp1(i, j - 1);
                visited[i][j - 1] = false;
                s.push(temp1);
            }
        }

        // Checking the down direction
        else if (d == 2)
        {
            if (i + 1 < n and maze[i + 1][j] and
                visited[i + 1][j])
            {
                node temp1(i + 1, j);
                visited[i + 1][j] = false;
                s.push(temp1);
            }
        }
        // Checking the right direction
        else if (d == 3)
        {
            if (j + 1 < m and maze[i][j + 1] and
                visited[i][j + 1])
            {
                node temp1(i, j + 1);
                visited[i][j + 1] = false;
                s.push(temp1);
            }
        }

        // If none of the direction can take
        // the rat to the Food, retract back
        // to the path where the rat came from.
        else
        {
            visited[temp.x][temp.y] = true;
            s.pop();
        }
    }

    // If the stack is empty and
    // no path is found return false.
    return false;
}

string removeDuplicates(string S)
{
    /*TODO*/
    int length = S.length();
    stack<char> myStack;

    for (int i = 0; i < length; i++)
    {
        if (myStack.empty() || S[i] != myStack.top())
            myStack.push(S[i]);
        else
            myStack.pop();
    }

    string result = "";
    while (!myStack.empty())
    {
        result = myStack.top() + result;
        myStack.pop();
    }
    return result;
}

// iostream, stack and vector are included

vector<int> nextGreater(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                arr[i] = arr[j];
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        else
        {
            arr[i] = -1;
        }
    }
    arr[n] = -1;
    return arr;
}

int evaluatePostfix(string expr)
{
    stack<int> result;

    std::string str = expr;
    std::stringstream ss(str);

    std::string token;
    while (ss >> token)
    {
        string s = token;
        if (s == "*")
        {
            int x1 = result.top();
            result.pop();
            int x2 = result.top();
            result.pop();
            result.push(x1 * x2);
        }
        else if (s == "+")
        {
            int x1 = result.top();
            result.pop();
            int x2 = result.top();
            result.pop();
            result.push(x1 + x2);
        }
        else if (s == "/")
        {
            int x1 = result.top();
            result.pop();
            int x2 = result.top();
            result.pop();
            if (x1 != 0)
            {
                result.push(x2 / x1);
            }
            else
            {
                return -1;
            }
        }
        else if (s == "-")
        {
            int x1 = result.top();
            result.pop();
            int x2 = result.top();
            result.pop();
            result.push(x2 - x1);
        }
        else
        {
            int temp = stoi(s);
            result.push(temp);
        }
    }
    return result.top();
}

int stoi(char ch)
{
    int i = ch - '0';
    return i;
}

int baseballScore(string ops) // Remember to include the stoi function above
{
    /*TODO*/
    stack<int> scores;
    int sum = 0;
    for (int i = 0; i < static_cast<int>(ops.length()); i++)
    {
        if (ops[i] == 'C')
        {
            sum -= scores.top();
            scores.pop();
        }
        else if (ops[i] == 'D')
        {
            int prev = scores.top();
            scores.push(prev * 2);
            sum += prev * 2;
        }
        else if (ops[i] == '+')
        {
            int prev1 = scores.top();
            scores.pop();
            int prev2 = scores.top();
            scores.push(prev1);
            scores.push(prev1 + prev2);
            sum += prev1 + prev2;
        }
        else
        {
            int score = stoi(ops[i]);
            scores.push(score);
            sum += score;
        }
    }

    return sum;
}

vector<int> stock_span(const vector<int> &ns)
{
    // STUDENT ANSWER

    vector<int> result(ns.size());
    stack<int> a, b;
    for (int i = 0; i < int(result.size()); i++)
    {
        result[i] = 1;
    }
    for (int i = 0; i < int(ns.size()); i++)
    {
        a.push(ns[i]);
    }
    while (!a.empty())
    {
        b = a;
        b.pop();
        while (!b.empty())
        {
            if (b.top() < a.top())
            {
                result[a.size() - 1] += 1;
                b.pop();
            }
            else
            {
                break;
            }
        }
        a.pop();
    }
    return result;
}

bool isValidParentheses(string s)
{
    /*TODO*/
    int length = s.length();
    if (s.length() == 0)
        return true;
    stack<char> myStack;
    char top;

    for (int i = 0; i < length; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            myStack.push(s[i]);
            continue;
        }

        else if (myStack.empty())
            return false;
        else
        {
            switch (s[i])
            {
            case ')':
                top = myStack.top();
                myStack.pop();
                if (top == '[' || top == '{')
                    return false;
                break;

            case ']':
                top = myStack.top();
                myStack.pop();
                if (top == '(' || top == '{')
                    return false;
                break;

            case '}':
                top = myStack.top();
                myStack.pop();
                if (top == '[' || top == '(')
                    return false;
                break;
            }
        }
    }
    return myStack.empty();
}



bool check(stack<char> st, int k, char x){
    int cnt = 0;
    while(!st.empty() && st.top() == x){
        cnt++;
        st.pop();
        if(cnt == k) break;
    }
    return (cnt == k);
}

string deleteDuplicate(string s, int k) {
    stack<char> st;
    for(char x : s){
        if(st.empty()){
            st.push(x);
        }else{
            if(x == st.top()){
                if(check(st, k-1, x)){
                    int tem = k-1;
                    while(!st.empty() && tem--){
                        st.pop();
                    }
                }else{
                    st.push(x);
                }
            }else{
                st.push(x);
            }
        }
    }
    if(st.empty()){
        return "-1";
    }
    string pre_res = "";
    while(!st.empty()){
        pre_res += st.top();
        st.pop();
    }
    string res = "";
    for(int i = pre_res.size()-1; i >= 0; i--){
        res += pre_res[i];
    }
    return res;
}