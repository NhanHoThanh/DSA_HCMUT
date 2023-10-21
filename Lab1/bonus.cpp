#include <vector>
#include <iostream>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int findMax(const std::vector<int> &nums, int startSkip, int endSkip)
{
    if (nums.empty())
    {
        std::cerr << "Vector is empty!" << std::endl;
        exit(1);
    }

    int max = INT_MIN;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
    {
        if (i >= startSkip && i <= endSkip)
        {
            continue;
        }
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }

    return max;
}

int findMin(const std::vector<int> &nums, int startSkip, int endSkip)
{
    if (nums.empty())
    {
        std::cerr << "Vector is empty!" << std::endl;
        exit(1);
    }

    int min = INT_MAX;
    for (int i = 1; i < static_cast<int>(nums.size()); ++i)
    {
        if (i >= startSkip && i <= endSkip)
        {
            continue;
        }
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }

    return min;
}

int findDifference(vector<int> &nums, int length)
{
    int min = nums[0];
    int max = nums[0];
    for (int i = 1; i < length; i++)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max - min;
}

int minimumAmplitude(vector<int> &nums, int k)
{
    if (nums.empty())
    {
        std::cerr << "Vector is empty!" << std::endl;
        exit(1);
    }
    if (k == 0)
    {
        findDifference(nums, static_cast<int>(nums.size()));
    }
    int startSkip = 0;
    int endSkip = k - 1;
    int result = INT_MAX;
    for (int i = 0; i < static_cast<int>(nums.size()); i++)
    {

        int amplitude = findMax(nums, startSkip, endSkip) - findMin(nums, startSkip, endSkip);
        if (amplitude < result)
        {
            result = amplitude;
        }
        startSkip++;
        endSkip++;
    }
    return result;
}
