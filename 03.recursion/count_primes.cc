/*
* Homework 15: Count primes
*
* int count_primes(int start, int end);
*   Compute how many primes between start & end, inclusive indices
* Don't use loops at all
* Input
*   10 20  => 4
*   10 200 => 42
*
* Can u compare answer for [10, 5000000] ?
*/

#include <iostream>

bool is_prime(unsigned  m, unsigned curr_test_number = 3) {
	if (m == 2) {
		return true;
	}
	else if (m <= 1 || m % 2 == 0) {
		return false;
	}
	else if (m == curr_test_number) {
		return true;
	}
	else if (m % curr_test_number == 0) {
		return false;
	}
	return is_prime(m, curr_test_number + 1);
}

int count_primes(unsigned  start, unsigned int end) {
	if (start > end) {
		return 0;
	}
	int result = count_primes(start + 1, end);
	if (is_prime(start)) {
		result += 1;
	}
	return result;
}

int main() {
	std::cout << count_primes(10, 20) << std::endl;
	std::cin.get();
	return 0;
}
