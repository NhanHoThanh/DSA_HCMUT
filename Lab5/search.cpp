#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        else
            return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int interpolationSearch(int arr[], int left, int right, int x) {
    int pos;
    if (left <= right && x >= arr[left] && x <= arr[right]) {
        pos = left + ((double)(right - left) / (arr[right] - arr[left]) * (x - arr[left]));
        cout << "We traverse on index: " << arr[pos - 1] << endl;
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, right, x);

        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, left, pos - 1, x);
    }
    return -1;
}
int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = sqrt(n);
    int prev = 0;
    int i;
    for (i = 0; i < n; i += step) {
        if (arr[i] <= x) prev = i;
        if (arr[i] == x) {
            cout << i;
            return i;
        }
        cout << i << " ";
        if (arr[i] > x) break;
    }
    if (prev > n - 1)
        return -1;
    else {
        for (int j = prev; j < i; j++) {
            if (arr[j] == x) {
                cout << j;
                return j;
            }
            if (j != prev) cout << j << " ";
            if (arr[j] > x) break;
        }
    }
    return -1;
}
bool findPairs(int arr[], int n, pair<int, int>& pair1, pair<int, int>& pair2) {
    map<int, pair<int, int>> map;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = arr[i] + arr[j];

            if (map.find(sum) == map.end()) {
                map[sum] = make_pair(i, j);
            } else {
                pair<int, int> p = map[sum];
                pair1 = make_pair(arr[p.first], arr[p.second]);
                pair2 = make_pair(arr[i], arr[j]);
                return true;
            }
        }
    }
    return false;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
}