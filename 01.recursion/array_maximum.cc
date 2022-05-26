/*
* Homework 3 : Array maximum
*
* int arr_max(int arr[], int len);
* Write a function that computes array maximum
* Input 1, 8, 2, 10, 3 => 10
*/

#include <iostream>

// my way 1
int arr_max_way1(const int arr[], int len) {
	if (len == 2) {
		return arr[0] > arr[1] ? arr[0] : arr[1];
	}
	const int ret = arr_max_way1(arr, len - 1);
	return arr[len - 1] > ret ? arr[len - 1] : ret;
}

// my way 2
int arr_max_way2(const int arr[], int len) {
	const int bigger = arr[len - 2] > arr[len - 1] ? arr[len - 2] : arr[len - 1];
	if (len == 2) {
		return bigger;
	}
	const int ret = arr_max_way2(arr, len - 2); // less recursive calls
	return bigger > ret ? bigger : ret;
}

// teacher's way
int arr_max(int arr[], int len) {
	if (len == 1) {
		return arr[0];
	}
	int sub_result = arr_max(arr, len - 1);
	return arr[len - 1] > sub_result ? arr[len - 1] : sub_result;
	//return max(sub_result, arr[len - 1]);
}

int main() {
	const int array[] = { 2, 103, 404, 5000, 12, -1, 11, 634 };
	std::cout << arr_max_way2(array, sizeof(array) / sizeof(*array)) << std::endl;
	return 0;
}
