/*
* Homework 13 : Is prefix
*
* bool is_prefix(string main, string prefix, int start_pos = 0);
* E.g. is_prefix("abcdefgh", "abcd") => true
* E.g. is_prefix("abcdefgh", "") => true
* E.g. is_prefix("abcdefgh", "abd") => false
*/

#include <string>
#include <iostream>

// my way
bool is_prefix(std::string main, std::string prefix, int start_pos = 0) {
	if (prefix.size() == start_pos) {
		return true;
	}
	bool check = main[start_pos] == prefix[start_pos];
	return check & is_prefix(main, prefix, ++start_pos);
}

// teacher's way
bool teach_is_prefix(std::string main, std::string prefix, int start_pos = 0) {
	if (prefix.size() == start_pos) {
		return true;
	}
	if (main[start_pos] != prefix[start_pos]) {
		return false;
	}
	return teach_is_prefix(main, prefix, start_pos + 1);
}

int main() {
	std::cout << "IS abcd PREFIX of abcdefgh: " << std::boolalpha << is_prefix("abcdefgh", "abcd") << std::endl;
	std::cout << "IS abd  PREFIX of abcdefgh: " << std::boolalpha << is_prefix("abcdefgh", "abd") << std::endl;
	std::cout << "IS ''   PREFIX of abcdefgh: " << std::boolalpha << is_prefix("abcdefgh", "") << std::endl;
	return 0;
}
