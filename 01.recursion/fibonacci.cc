/*
* Homework 17: Fibonacci
*
* Implement fibonacci: int fibonacci(int n)
* Recall fibonacci sequence: 1 1 2 3 5 8 13 21 35
* E.g. fibonacci(6) = 13
* Recall that: fibonacci(n) = fibonacci(n-1) + fibonacci(n-2).
* E.g. fib(6) = fib(5) + fib(4) = 13
*	So it calls 2 subproblems of its type
*
* Can u compute fibonacci(40) ? fibonacci(50) ? Why ? Any work around ?
* Hint: Array
*/

#include <iostream>

unsigned long long fibonacci(unsigned n) {
	if (n <= 1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n;
	std::cout << "Enter FIBONNACI number: ";
	std::cin >> n;
	std::cout << "FIBONACCI of " << n << " is " << fibonacci(n) << std::endl;
	return 0;
}
