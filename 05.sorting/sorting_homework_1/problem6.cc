/***
* Problem #6: Count sort version 2
*
* There is another popular implementation for the count sort
* Please study and understand the code
* Compare the implementation with the lectue implementation
*   What are the pros & cons ?
*
* Observer: the first 2 blocks are the same as the code lecture
* The difference is in how to build the output
**/

#include <iostream>
#include <vector>

using namespace std;
vector<int> countSort(const vector<int>& array) {
	// Find the largest element of the array
	int size = array.size();
	int mxVal = array[0];
	for (int i = 1; i < size; ++i) {
		if (array[i] > mxVal) {
			mxVal = array[i];
		}
	}

	// Compute Frequency
	vector<int> count(mxVal + 1); // zeros
	for (int i = 0; i < size; ++i) {
		count[array[i]] += 1;
	}

	// acumulate the counting
	for (int i = 1; i <= mxVal; ++i) {
		count[i] += count[i - 1];
	}

	// Find the index and put the number
	vector<int> output(size);
	for (int i = size - 1; i >= 0; --i) {
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	return output;
}

int main() {
	return 0;
}