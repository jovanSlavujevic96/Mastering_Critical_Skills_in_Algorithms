/*
* Homework 5 : Array Average
*
* double average(int arr[], int len);
* Write a func that computes array average
* NOTE: don't divide by length in the main
*
* Input: 1, 8, 2, 10, 3 => 4.8
*/

#include <iostream>

double average(const int arr[], int len) {
	if (len == 1) {
		return arr[0];
	}
	return (average(arr, len - 1) * (len - 1) + arr[len - 1]) / len;
}

// teacher's way => SAME THING
double arr_average(int arr[], int len) {
	if (len == 1) {
		return arr[0];
	}

	double sub_result = arr_average(arr, len - 1);
	sub_result = sub_result * (len - 1);

	return (sub_result + arr[len - 1]) / len;
}

int main() {
	const int array[] = {1, 8, 2, 10, 3};
	std::cout << "average is: " << average(array, sizeof(array) / sizeof(*array));
	return 0;
}
