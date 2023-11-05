int flag(int n, int m, vector<int> a, vector<int> b)
{
    map<int, int> map;

    for (const int &e : a)
    {
        map[e]++;
    }

    for (const int &e : b)
    {
        map[e]++;
    }

    vector<pair<int, int>> pairs(map.begin(), map.end());

    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });

    int flags = 0;
    int minColors = 0;

    for (const pair<int, int> &pair : pairs)
    {
        if (flags < n)
        {
            flags += pair.second;
            minColors++;
        }
    }

    return minColors;
}