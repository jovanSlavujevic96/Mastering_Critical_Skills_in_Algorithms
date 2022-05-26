#include <iostream>

void print_triangle(int levels) {
	if (levels == 0)
		return;

	print_triangle(levels - 1);

	for (int i = 0; i < levels; i++) {
		std::cout << "*";
	}
	std::cout << "\n";
}

int main() {
	print_triangle(5);
	return 0;
}
