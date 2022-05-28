/*
* Homework 12 : Is Palindrome
*
* Implement a func that decides if array is palindrome or not
* Define it's signature
*/

#include <iostream>

// my way
bool is_palindrome(const int arr[], int len, int start_pos = 0) {
	int DECR = 0;

	// odd num
	if (len % 2) {
		DECR = 1;
	}
	if (len - start_pos - DECR == start_pos) {
		return true;
	}
	return (arr[len - start_pos - 1] == arr[start_pos]) & is_palindrome(arr, len, start_pos + 1);
}

// teacher's way 1
bool is_palindrome_v1(const int arr[], int start, int end_idx) {
	if (start >= end_idx) {
		return true;
	}
	if (arr[start] != arr[end_idx]) {
		return false;
	}
	return is_palindrome_v1(arr, start + 1, end_idx - 1);
}

// teacher's way 2
bool is_palindrome_v2(const int arr[], int end_idx) {
	if (end_idx <= 0) {
		return true;
	}
	if (arr[0] != arr[end_idx]) {
		return false;
	}
	return is_palindrome_v2(arr + 1, end_idx - 2);
}

int main() {
	const int array[] = { 1, 8, 2, 8, 1 };
	std::cout << "Is array palindrome ? " << std::boolalpha << is_palindrome(array, sizeof(array) / sizeof(*array)) << std::endl;
	std::cout << "Is array palindrome ? " << std::boolalpha << is_palindrome_v2(array, sizeof(array) / sizeof(*array)-1) << std::endl;
	std::cin.get();
	return 0;
}
