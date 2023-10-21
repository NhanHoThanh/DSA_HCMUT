#include <string.h>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;

int charToInt(char digit_char)
{
    return digit_char - '0';
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
    for (int i = 0; i < static_cast<int>(expr.length()); i++)
    {
        string s;
        while (expr[i] != ' ' || expr[i] == '/n')
        {
            cout << "running" << endl;
            s.push_back(expr[i]);
            i++;
        }
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

int main()
{
    std::cout << evaluatePostfix("100 200 + 2 / 5 * 7 +");
    return 0;
}
