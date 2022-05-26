#include <iostream>

void sequence(int n) {
	std::cout << n << ' ';
	// last number
	if (n == 1) {
		return;
	}
	// even number
	else if (n % 2 == 0) {
		sequence(n / 2);
	}
	// odd number
	else {
		sequence(3 * n + 1);
	}
}

int main() {
	sequence(5);
	return 0;
}