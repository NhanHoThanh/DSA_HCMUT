// 0.9/1.0

static void merge(T *start, T *middle, T *end)
{
    // TODO
    int len1 = middle - start + 1;
    int len2 = end - middle;
    T left[len1];
    T right[len2];

    for (int i = 0; i < len1; i++)
        left[i] = *(start + i);
    for (int i = 0; i < len2; i++)
        right[i] = *(middle + 1 + i);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            *(start + k) = left[i];
            i++;
        }
        else
        {
            *(start + k) = right[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        *(start + k) = left[i];
        k++;
        i++;
    }

    while (j < len2)
    {
        *(start + k) = right[j];
        k++;
        j++;
    }
}

static void InsertionSort(T *start, T *end)
{
    // TODO
    for (T *i = start + 1; i <= end; i++)
    {
        T temp = *i;
        T *j = i - 1;
        while (j >= start && *j > temp)
        {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = temp;
    }
}

static void TimSort(T *start, T *end, int min_size)
{
    // TODO
    // You must print out the array after using insertion sort and everytime calling method merge.
    int n = end - start + 1;

    for (T *i = start; i < end; i += min_size)
    {
        InsertionSort(i, std::min(i + min_size - 1, end - 1));
    }
    cout << "Insertion Sort: ";
    printArray(start, end);

    int i = 1;
    for (int size = min_size; size < n; size = 2 * size)
    {
        for (T *left = start; left < end; left += 2 * size, ++i)
        {
            int *mid = left + size - 1;
            int *right = std::min(left + 2 * size - 1, end - 1);
            if (mid < right)
            {
                merge(left, mid, right);
            }
            cout << "Merge " << i << ": ";
            printArray(start, end);
        }
    }
}