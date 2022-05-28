/***
* Problem #5: Count sort for strings v2
*
* Implement void countSort(vector<string>& array)
* The function updates a vector of string sorted using count sort
* Consider the following constraints
*   Every string consists only lower letters (a-z) and is of length >= 1
*   The sorting is only based on the first two characters of a string
*   The algorithm must be stable
* Input example: axz, xaz, axa, zzz, abc, abe
* Outptu:        abc, abe, axz, axa, xaz, zzz
*   Prefix ab must come before ax. Within each group, respect the input order
**/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

// MY WAY
void countSort(vector<string>& array) {
	// Find the largest element of the array
	const int size = array.size();
	char mxValue1 = array[0][0];
	char mxValue2 = array[0][1];
	for (int i = 1; i < size; ++i) {
		if (array[i][0] > mxValue1) {
			mxValue1 = array[i][0];
		}
		if (array[i][1] > mxValue2) {
			mxValue2 = array[i][1];
		}
	}

	const size_t countLen = (uint16_t)(mxValue2 - 'a') | (mxValue1 - 'a') << 8;

	// Compute Frequency
	vector<vector<string>> count(countLen + 1);	// zeros
	for (int i = 0; i < size; ++i) {
		count[(uint16_t)(array[i][1] - 'a') | (array[i][0] - 'a') << 8].push_back(array[i]);
	}

	// Put the values back to the array
	int idx = 0;
	for (int i = 0; i <= countLen; ++i) {
		for (int j = 0; j < count[i].size(); ++j, ++idx)
			array[idx] = count[i][j];
	}
}

// teacher's way
const int LETTERS_SZ = 26;

// Convert a string to an index in range [0 to 26*26-1]
int id(const string& str) {
	assert(str.size() >= 2);
	int f = str[0] - 'a';
	int s = str[1] - 'a';

	return f * LETTERS_SZ + s;
}

void teacher_countSort(vector<string>& array) {
	int size = array.size();
	int range = LETTERS_SZ * LETTERS_SZ;
	vector<vector<string>> letter_to_strings(range);

	for (int i = 0; i < size; ++i)
		letter_to_strings[id(array[i])].push_back(array[i]);

	int idx = 0;
	for (int letter = 0; letter < range; ++letter) {
		for (int str_idx = 0; str_idx < (int)letter_to_strings[letter].size(); ++str_idx, ++idx)
			array[idx] = letter_to_strings[letter][str_idx];
	}
}

int main() {
	{
		std::vector<std::string> input = { "xbf", "axz", "xaz", "axa", "zzz", "abc", "abe" };
		countSort(input);

		for (std::string& in : input) {
			std::cout << in << " ";
		}
		std::cout << std::endl;
	}
	{
		std::vector<std::string> input = { "xbf", "axz", "xaz", "axa", "zzz", "abc", "abe" };
		teacher_countSort(input);

		for (std::string& in : input) {
			std::cout << in << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}