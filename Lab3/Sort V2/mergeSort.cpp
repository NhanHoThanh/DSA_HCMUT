static void merge(T *left, T *middle, T *right)
{
    /*TODO*/
    int subArrayOne = middle - left + 1;
    int subArrayTwo = right - middle;
    T *leftArray = new T[subArrayOne];
    T *rightArray = new T[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = left[i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = middle[j + 1];
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = 0;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            left[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            left[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        left[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        left[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;

    Sorting::printArray(left, right);
}
static void mergeSort(T *start, T *end)
{
    /*TODO*/
    if (start >= end)
    {
        return;
    }
    int n = 0;
    for (auto i = start; i != end; i++)
    {
        n++;
    }
    int mid = n / 2;

    mergeSort(start, start + mid);
    mergeSort(start + mid + 1, end);
    merge(start, start + mid, end);
}