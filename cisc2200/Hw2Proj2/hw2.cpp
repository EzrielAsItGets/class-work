#include <iostream>
#include <algorithm>

const int SIZE = 100;

using namespace std;

void print(int arr[], int size);
int fib(int n);
int countWays(int n);
int firstIndex(int arr[], int begin, int end, int target, int size_local);
void rotate(int arr[], int d, int n);
void restore(int arr[], int n);
void swapCustom(int *a, int *b);
int partition(int arr[], int low, int high, int k);
int median(int arr[], int left, int right, int kth);

int main() {
    int n, target, size_local = 7, size_local1 = 5, size_local2 = 6, size_local3 = 5, k;
    int arr[SIZE] = {1, 2, 3, 3, 4, 5, 10}, arr1[SIZE] = {1, 2, 3, 4, 5},
        arr2[SIZE] = {6, 5, 4, 1, 2, 3}, arr3[SIZE] = {3, 2, 1, 4, 5};
    
    cout << "\n******Counting Ways******\n";
    n = 3;
    cout << "Input: n = " << n << endl;
    cout << "If n = " << n << ", there are " << countWays(n) << " to climb to the top.\n";
    cout << endl;
    
    cout << "******Binary Search******\n";
    target = 3;
    cout << "Input: target = " << target << endl;
    cout << "If the given array is {";
    print(arr, size_local);
    cout << "}, for given target " << target << ", return " << firstIndex(arr, 0, size_local - 1, target, size_local) << ".\n";
    cout << endl;
    
    cout << "******Recover Sorted Array******\n";
    cout << "The original array is {";
    print(arr1, size_local1);
    cout << "}, which is then rotated to become {";
    rotate(arr1, 3, size_local1);
    print(arr1, size_local1);
    cout << "}.\n";
    restore(arr1, size_local1);
    cout << "The restored array is {";
    print(arr1, size_local1);
    cout << "}.\n";
    cout << endl;
    
    cout << "******Partition Array******\n";
    cout << "The original array is {";
    print(arr2, size_local2);
    cout << "}.\n";
    k = 2;
    cout << "The original index is: " << k + 1 << endl;
    cout << "The element chosen for pivot is: " << arr2[k] << endl;
    cout << "The index after partition is: " << partition(arr2, 0, size_local2, k) << endl;
    cout << endl;
    
    cout << "******Find Median******\n";
    cout << "The given array is {";
    print (arr3, size_local3);
    cout << "}.\n";
    cout << "The median is: " << median(arr3, 0, size_local3, size_local3 / 2) << endl;
    cout << endl;
         
    return 0;
}

void print(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
    	cout << arr[i] << ", ";
    cout << arr[size - 1];
}

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
    
}

int countWays(int n) {
    return fib(n + 1);
}

int firstIndex(int arr[], int begin, int end, int target, int size_local) {
    if (end >= begin) {
        int mid = begin + (end - begin) / 2;
        if ((mid == 0 || target > arr[mid - 1]) && arr[mid] == target)
            return mid;
        else if (target > arr[mid])
            return firstIndex(arr, (mid + 1), end, target, size_local);
        else
            return firstIndex(arr, begin, (mid - 1), target, size_local);
    }
    return -1;
}

void rotate(int arr[], int d, int n) {
    int temp[d];
    int it = 0;
    for (int i = 0; i < d; ++i) 
        temp[i] = arr[i];
    for (int i = 0; i < n - d; ++i) 
        arr[i] = arr[i + d];
    for (int i = n - d; i < n; ++i) 
        arr[i] = temp[it++];
}

void restore(int arr[], int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] > arr[i + 1]) {
            reverse(arr, arr + i + 1);
            reverse(arr + i + 1, arr + n);
            reverse(arr, arr + n);
        }
}

void swapCustom(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int k) {
    int pivot = arr[k];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
        if (arr[j] <= pivot) {
            i++;
            swapCustom(&arr[i], &arr[j]);
        }
    swapCustom(&arr[i + 1], &arr[k]);
    return (i + 1);
}

int median(int arr[], int left, int right, int kth) {
    for (;;) {
        int pivotIndex = partition(arr, left, right, kth);
        int len = pivotIndex - left + 1;
        if (kth == len)
            return arr[pivotIndex];
        else if (kth < len)
            right = pivotIndex - 1;
        else {
            kth = kth - len;
            left = pivotIndex + 1;
        }
    }
}
