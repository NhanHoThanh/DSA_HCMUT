string minDiffPairs(int *arr, int n)
{
    sort(arr, arr + n);
    int minDiff = arr[1] - arr[0];
    stringstream result;

    for (int i = 2; i < n; i++)
    {
        minDiff = min(minDiff, arr[i] - arr[i - 1]);
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == minDiff)
        {
            result << "(" << arr[i - 1] << ", " << arr[i] << "), ";
        }
    }

    string resultStr = result.str();
    if (!resultStr.empty())
    {
        resultStr = resultStr.substr(0, resultStr.length() - 2);
    }

    return resultStr;
}