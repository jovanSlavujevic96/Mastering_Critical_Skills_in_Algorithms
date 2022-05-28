/*
* Homework 6 : Array increment
*
* void array_increment(int arr[], int len);
*
* The func increments each arr[i] with i
* E.g. for input
*	[1, 2, 5, 9] it be [1+0, 2+1, 5+2, 9+3]
*   1 8 2 10 3 => 1 9 4 13 7
*/

#include <iostream>

void array_increment(int arr[], int len) {
	if (len == 1) {
		return;
	}
	arr[len - 1] += len - 1;
	array_increment(arr, len - 1);
}

int main() {
	int array[] = { 1,8,2,10,3 };
	array_increment(array, sizeof(array) / sizeof(*array));

	std::cout << "FINAL ARRAY: " << std::endl;
	for (int i : array) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}
