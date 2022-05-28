// Homework 1 : 3n+1 Length
// implement 3n+1 func to compute the length of the sequence
// int length_3n_plus_1(int n)
// E.g. length_3n_plus_1(6) => 9

#include <iostream>

int length_3n_plus_1(int n) {
	std::cout << n << ' ';

	if (n == 1) {
		return 1;
	}
	// even number
	else if (n % 2 == 0) {
		return 1 + length_3n_plus_1(n / 2);
	}
	// odd number
	else {
		return 1 + length_3n_plus_1(3 * n + 1);
	}
}

int main() {
	int input;

	std::cout << "Enter the 3n+1 sequence input: ";
	std::cin >> input;
	
	const int len = length_3n_plus_1(input);

	std::cout << std::endl;

	std::cout << "len of 3n+1 sequence for " << input << " is " << len << std::endl;
	return 0;
}
