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

using namespace std;

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

int main() {
	std::vector<std::string> input = { "xbf", "axz", "xaz", "axa", "zzz", "abc", "abe" };
	countSort(input);

	for (std::string& in : input) {
		std::cout << in << " ";
	}
	std::cout << std::endl;
	return 0;
}