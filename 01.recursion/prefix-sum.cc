/*
* Homework 11 : Prefix Sum
*
* Write a func that sums only the first N elements in array.
* Define it's signature
* Input [1, 3, 4, 6, 7], 3 => 8 (1 + 3 +4)
*/

#include <iostream>

// my way
int preffix_sum(const int arr[], int N) {
	if (N == 0) {
		return 0;
	}
	return arr[N - 1] + preffix_sum(arr, N - 1);
}

// teacher's way 1
int prefix_sum_v1(const int arr[], int len, int cnt) {
	if (cnt == 0)
		return 0;
	return arr[cnt - 1] + prefix_sum_v1(arr, len - 1, cnt - 1);
}

// teacher's way 2
int prefix_sum_v2(const int arr[], int cnt) {
	if (cnt == 0)
		return 0;
	return arr[cnt - 1] + prefix_sum_v2(arr, cnt - 1);
}

int main() {
	const int array[] = { 1,3,4,6,7 };
	std::cout << "PREFFIX SUM is " << preffix_sum(array, 3) << std::endl;
	std::cout << "PREFFIX SUM is " << prefix_sum_v2(array, 3) << std::endl;
	return 0;
}
