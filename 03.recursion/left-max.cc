/**
* Homework 8 : Left-Max
*
* Given array, change each element at position i to be the maximum of numbers from 0 to index i
* E.g. input 1 3 5 7 4 2 => [1, 3, 5, 7, 7, 7]
* void left_max(int arr[], int len);
*/

#include <iostream>

// may way
void l_max(int arr[], int len) {
	if (len == 1) {
		return;
	}
	for (int i = 0; i < len - 1; ++i) {
		if (arr[i] > arr[len - 1]) {
			arr[len - 1] = arr[i];
		}
	}
	l_max(arr, len - 1);
}

// teacher's way
void left_max(int arr[], int len) {
	if (len == 1)
		return;

	l_max(arr, len - 1);
	if (arr[len - 2] > arr[len - 1]) {
		arr[len - 1] = arr[len - 2];
	}
	//arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}

int main() {
	int array[] = { 1,3,5,7,4,2 };
	left_max(array, sizeof(array) / sizeof(*array));

	std::cout << "FINAL ARRAY:\n";
	for (int i : array) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}
