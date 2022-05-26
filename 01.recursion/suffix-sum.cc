/*
* Homework 10 : Suffix Sum
*
* Write a func that sums only the last N elemeents in an array.
* Define it's signature
* Input [1, 3, 4, 6, 7], 3 => 17 (4 + 6 + 7)
*/

#include <iostream>

// my way
int suffix_sum(const int arr[], int len, int N) {
	if (N == 0) {
		return 0;
	}
	return arr[len - N] + suffix_sum(arr, len, N - 1);
}

// teacher's way
int sum(const int arr[], int len, int cnt) {
	if (!cnt)
		return 0;
	return arr[len - 1] + suffix_sum(arr, len - 1, cnt - 1);
}

int main() {
	const int array[] = { 1,3,4,6,7 };
	std::cout << "SUFFIX SUM is " << suffix_sum(array, sizeof(array) / sizeof(*array), 3) << std::endl;
	return 0;
}
