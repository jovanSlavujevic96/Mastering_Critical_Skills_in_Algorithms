/**
* Homework 4: Array Sum
*
* int sum(int arr[], int len);
* Write a func that computes array sum
* Input 1, 8, 2, 10, 3 => 24
*/

#include <iostream>

int sum(const int arr[], int len) {
	if (len == 1) {
		return arr[0];
	}
	return arr[len - 1] + sum(arr, len - 1);
}

int main() {
	const int array[] = { 1,8,2,10,3 };
	std::cout << "SUM is: " << sum(array, sizeof(array) / sizeof(*array)) << std::endl;
	return 0;
}
