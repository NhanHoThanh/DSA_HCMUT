#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int stackSum(stack<int> &st)
{
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    st = stack<int>(); // clear the stack
    return sum;
}
int mountainWithoutValley(vector<int> &nums)
{
    stack<int> s;
    int max = 0;
    int sum = 0;

    // STUDENT ANSWER
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        s.push(nums[i]);
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < s.top())
            {
                s.push(nums[j]);
            }
            else
            {
                s.push(s.top());
            }
        }
        for (int k = i - 1; k >= 0; k--)
        {
            if (nums[k < s.top)
        }
    }
}

int main()
{

    vector<int> nums{10, 6, 8, 8};
    cout << mountainWithoutValley(nums);
}

int mountainWithoutValley(vector<int> &nums)
{
    stack<int> st;
    int sum = 0;
    int n;
    n = nums.size();
    int a[n] = {0};
    a[0] = nums[0];
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        if (nums[st.top()] > nums[i])
        {
            while (!st.empty() && st.top() > nums[i])
            {
                a[st.top()] = nums[st.top()];
                st.pop();
            }
            st.push(i);
        }
        else
        {
            a[i] = nums[st.top()];
        }
    }
    while (!st.empty())
    {
        a[st.top()] = nums[st.top()];
        st.pop();
    }
    bool check_tang = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            a[i] = nums[i];
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << " ";
        sum += a[i];
    }
    return sum;
}

/*
        s.push(nums[i]);
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[j - 1])
            {
                s.push(nums[j]);
            }
            else
            {
                int top = s.top();
                s.push(top);
            }
        }
        for (int k = i - 1; k > 0; k++)
        {
            if (nums[k] < nums[k + 1])
            {
                s.push(nums[k]);
            }
            else
            {
                int top = s.top();
                s.push(top);
            }
        }
        for (int t = 0; t < s.size(); t++)
        {
            sum += s.top();
            s.pop();
        }
        if (sum > max)
        {
            max = sum;
        }
        sum = 0;
*/