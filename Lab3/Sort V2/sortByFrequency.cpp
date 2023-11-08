struct Element
{
    int value;
    int frequency;
    int originalIndex;
};

bool compare(const Element &a, const Element &b)
{
    if (a.frequency != b.frequency)
        return a.frequency > b.frequency;
    else
        return a.originalIndex < b.originalIndex;
}

void sortByFrequency(int arr[], int n)
{
    std::vector<Element> elements(n);
    for (int i = 0; i < n; i++)
    {
        elements[i].value = arr[i];
        elements[i].frequency = 0;
        elements[i].originalIndex = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == elements[j].value)
            {
                elements[j].frequency++;
                break;
            }
        }
    }

    stable_sort(elements.begin(), elements.end(), compare);

    int index = 0;
    for (const Element &element : elements)
    {
        Element copy = element;
        while (copy.frequency > 0)
        {
            arr[index] = copy.value;
            index++;
            copy.frequency--;
        }
    }
}