/*
* Homework 9 : Right-Max
*
* Given array, change each element at position i to be the maxmium of
* numbers from index i to end of array
*
* E.g. input 1 3 5 7 4 2 => [7, 7, 7, 7, 4, 2]
* void right_max(int arr[], int len, int start_position = 0);
*/

#include <iostream>

// my way
void right_max(int arr[], int len, int start_position = 0) {
	if (start_position + 1 == len) {
		return;
	}
	if (arr[len - start_position - 1] > arr[len - start_position - 2]) {
		arr[len - start_position - 2] = arr[len - start_position - 1];
	}
	right_max(arr, len, ++start_position);
}

// teacher's way 1
void right_max_v1(int arr[], int len, int start_pos = 0) {
	if (start_pos == len - 1) {
		return;
	}
	right_max_v1(arr, len, start_pos + 1);
	arr[start_pos] = (arr[start_pos] > arr[start_pos + 1]) ? arr[start_pos] : arr[start_pos + 1];
}

// teacher's way 2
void right_max_v2(int arr[], int len) {
	if (len == 1) {
		return;
	}
	right_max_v2(arr + 1, len - 1); // arr+1 is the new array shifted
	                                // E.g. {1,8,2,10,3} => {8,2,10,3}
	arr[0] = (arr[0] > arr[1]) ? arr[0] : arr[1];
}

int main() {
	int array[] = { 1,8,2,10,3 };
	right_max_v2(array, sizeof(array) / sizeof(*array));

	std::cout << "FINAL ARRAY:\n";
	for (int i : array) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}
