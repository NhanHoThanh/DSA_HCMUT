#include <stdio.h>
// SAP XEP TANG DAN || CAU 1,4
// Bubble Sort || Do phuc tap O(n^2) || Khong gian: O(1)
void ascending(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// SAP XEP GIAM DAN || CAU 1,4
// Bubble Sort || Do phuc tap O(n^2) || Khong gian: O(1)
void descending(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Nhap so vao mang
void saveToArr(int arr[], int n) {
    printf("Nhap %d so:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// TIM PHAN TU LON NHAT/NHO NHAT || CAU 2,4
// Do phuc tap: O(n) || Khong gian: O(1)
int findMax(int arr[], int n) {
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}
int findMin(int arr[], int n) {
    int min_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    return min_value;
}

// TIM SO NGUYEN TO TRONG MANG || CAU 4
// Do phuc tap: O(n) || Khong gian: O(1)
int isPrime(int num) {
    if (num < 2) return 0;
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

void findAndPrintPrime(int arr[],int n){ 
    for(int i = 0; i < n; i++) {
        if(isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
}

// BAI 3 || Cho 1 mang da sap xep, tim 1 phan tu trong mang do, neu ko tim dc thi tra ve -1
// tham so truyen vao: mang, size cua mang, gia tri can tim || Do phuc tap: O(logN) || Khong gian: O(1)
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // target not found
}

int main() {
    int n;
    printf("Nhap so luong: ");
    scanf("%d", &n);

    int arr[n];
    saveToArr(arr, n);

    findAndPrintPrime(arr, n);

    return 0;
}
