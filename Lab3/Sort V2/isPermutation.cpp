/* Your helping functions go here */
bool isPermutation(string a, string b)
{
    // TODO
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b)
        return 1;
    return 0;
}