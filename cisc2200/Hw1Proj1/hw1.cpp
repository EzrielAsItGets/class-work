#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

const int SIZE = 100;

using namespace std;

void initialize(int arr[], int n);
void swap(int *xp, int *yp);
void sortAscending(int arr[], int n);
void print(int arr[], int n);
void rotate(int arr[], int d, int n);
int maxProfit(int arr[], int n);
void pushZerosToEnd(int arr[], int n);
void mergeArrays(int arr[], int arr1[], int n, int n1, int arr2[]);
int findMajority(int arr[], int n);

int main() {
	srand(time(NULL));
	int n, n1, d, maj;
	int arr[SIZE], arr1[SIZE], arr2[SIZE];
	
	cout << endl << "******Rotation Function******" << endl;
	cout << "Enter an array size: ";
	cin >> n;
	initialize(arr, n);
	cout << "Original Array:";
	print(arr, n);
	cout << "Enter amount for rotation: ";
	cin >> d;
	rotate(arr, d, n);
	cout << "Rotated Array:";
	print(arr, n);
	cout << endl;
	
	cout << "******Maximum Profit Function******" << endl;
	cout << "Enter an array size: ";
	cin >> n;
	initialize(arr, n);
	cout << "Prices for the day:";
	print(arr, n);
	cout << "Maximum Profit: " << maxProfit(arr, n);
	cout << endl << endl;
	
	cout << "******Push Zeros To End Function******" << endl;
	cout << "Enter an array size: ";
	cin >> n;
	initialize(arr, n);
	cout << "Original Array:";
	print(arr, n);
	pushZerosToEnd(arr, n);
	cout << "Rearranged Array:";
	print(arr, n);
	cout << endl;
	
	cout << "******Merge Arrays******" << endl;
	cout << "Enter a size for Array 1: ";
	cin >> n;
	initialize(arr, n);
	sortAscending(arr, n);
	cout << "Enter a size for Array 2: ";
	cin >> n1;
	initialize(arr1, n1);
	sortAscending(arr1, n1);
	cout << "Array 1:";
	print(arr, n);
	cout << "Array 2:";
	print(arr1, n1);
	mergeArrays(arr, arr1, n, n1, arr2);
	sortAscending(arr2, n + n1);
	cout << "Merged Array:";
	print(arr2, n + n1);
	cout << endl;
	
	cout << "******Find Majority Function******" << endl;
	cout << "Enter an array size: ";
	cin >> n;
	initialize(arr, n);
	cout << "Array:";
	print(arr, n);
	maj = findMajority(arr, n);
	if (maj != -1)
		cout << "The majority is: " << maj << endl;
	else
    	cout << "There is no majority!" << endl;
	cout << endl;
	
	return 0;
}

void initialize(int arr[], int n) {
	for (int i = 0; i < n; ++i)
	    arr[i] = (double) 11 * rand() / RAND_MAX;
}

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sortAscending(int arr[], int n) {
	int i, j;
	for (i = 0; i < n-1; ++i) 
		for (j = 0; j < n - i - 1; ++j) 
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void print(int arr[], int n) {
	for (int i = 0; i < n; ++i) 
		cout << setw(4) << arr[i];
	cout << endl;
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

int maxProfit(int arr[], int n) {
	int max = arr[1], min = arr[0];
	int max_diff = max - min;
	for (int i = 1; i < n; ++i) {
		if (arr[i] > max) 
		    max = arr[i];
		if (arr[i] < min) 
		    min = arr[i];
		if (max - min > max_diff) 
		    max_diff = max - min;
	}
	return max_diff;
}

void pushZerosToEnd(int arr[], int n) {
	int it = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i] > 0)
			arr[it++] = arr[i];
	while (it < n)
		arr[it++] = 0;
			
}

void mergeArrays(int arr[], int arr1[], int n, int n1, int arr2[]) {
	int temp = 0;
	for (int i = 0; i < n; ++i)
		arr2[i] = arr[i];
	for (int i = n; i < n + n1; ++i)
		arr2[i] = arr1[temp++];
}

int findMajority(int arr[], int n) {
	unordered_map<int, int> map;
	for (int i = 0; i < n; ++i)
		map[arr[i]]++;
	for (auto pair: map)
		if (pair.second > n / 2)
			return pair.first;
	return -1;
}
