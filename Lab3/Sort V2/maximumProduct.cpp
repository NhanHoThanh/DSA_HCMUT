int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;
    sort(nums.begin(), nums.end());
    int arr[4];
    arr[0] = nums[0] * nums[1] * nums[2];
    arr[1] = nums[n - 1] * nums[n - 2] * nums[n - 3];
    arr[2] = nums[n - 1] * nums[n - 2] * nums[0];
    arr[3] = nums[n - 1] * nums[0] * nums[1];
    int ans = arr[0];
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }
    return ans;
}