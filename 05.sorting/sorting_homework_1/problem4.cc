/***
* Problem #4: Count sort for strings v1
*
* Implement void countSort(vector<string>& array)
* The function updates a vector of string sorted using count sort
* Consider the following constraints
*   Every string consists only lower letters (a-z) and is of length >= 1
*   The sorting is only based on the first character of a string
*   The algorithm must be stable
* Input example: ziad, belal, adam, baheir, ali
* Output:        adam, ali, belal, baheir, ziad
* Note: belal is equal to baheir, as sorting is only based on letter
* We must maintaint input order to be stable, so belal comest first
**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void countSort(vector<string>& array) {
	// Find the largest element of the array
	const int size = array.size();
	char mxValue = array[0][0];
	for (int i = 1; i < size; ++i)
		if (array[i][0] > mxValue)
			mxValue = array[i][0];

	// Compute Frequency
	vector<vector<string>> count((size_t)mxValue - 'a' + 1);	// zeros
	for (int i = 0; i < size; ++i)
		count[(size_t)array[i][0] - 'a'].push_back(array[i]);

	// Put the values back to the array
	int idx = 0;
	for (int i = 0; i <= mxValue - 'a'; ++i) {
		for (int j = 0; j < count[i].size(); ++j, ++idx)
			array[idx] = count[i][j];
	}
}

int main() {
	std::vector<std::string> input = { "ziad", "belal", "adam", "baheir", "ali" };
	countSort(input);

	for (std::string& in : input) {
		std::cout << in << " ";
	}
	std::cout << std::endl;
	return 0;
}