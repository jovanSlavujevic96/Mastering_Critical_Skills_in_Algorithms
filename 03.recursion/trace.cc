/*
* Homework 14 : Trace
*
* Without running code on the right
* Trace by hand: What does this method do
* What happens if we swapped lines 6 & 7
*/

// Q: What does this method do ?
// A: This function prints module of 10 for passed number and passes it recursivley divided by 10 if the passed number is different than zero

// Q: What happens if we swapped lines 6 & 7
// A: Printing sequence will be reversed

#include <iostream>

void do_something(int n) {
	if (n) {
		std::cout << n % 10;
		do_something(n / 10);
	}
}

int main() {
	do_something(123456); // prints: 654321
	std::cin.get();
	return 0;
}
