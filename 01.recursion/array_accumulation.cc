/*
* Homework 7 : Array accumulation
*
* Given an array we want to accumulate it as following:
* input 1 2 3 4 5 6
* output array
*   1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5, 1+2+3+4+5+6
*   1, 3, 6, 10, 15, 21
*
* That is return arr[i] = sum of all numbers from 0 to i
*
* void accumulate_arr(int arr[], int len);
* input 1 8 2 10 3 => 1 9 11 21 24
*/

#include <iostream>

// my way
void accumulate(int arr[], int len) {
	if (len == 1) {
		return;
	}
	for (int i = 0; i < len - 1; i++) {
		arr[len - 1] += arr[i];
	}
	accumulate(arr, len - 1);
}

// teacher's way
void accumulate_arr(int arr[], int len) {
	if (len == 1)
		return;

	accumulate_arr(arr, len - 1); // like reverse triangle !!!

	arr[len - 1] += arr[len - 2];
}

int main() {
	int array[] = { 1,8,2,10,3 };
	accumulate_arr(array, sizeof(array) / sizeof(*array));

	std::cout << "FINAL ARRAY: " << std::endl;
	for (int i : array) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}
