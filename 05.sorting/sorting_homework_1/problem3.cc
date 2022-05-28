/***
* Problem #3: Count Sort for a range
*
* Develop a count sort version to handle the following requirements:
*   Values range: -10^9 <= nums[i] <= 10^9
*   However: the max value - min value <= 500
* Input : nums = [10'000'107, 10'000'035, 10'000'001]
* Output:        [10'000'001, 10'000'035, 10'000'107]
* Online judge (can be helpful): LeetCode 912 - Sort an Array
**/

#include <iostream>
#include <vector>

#define LIMIT 500

using namespace std;

void countSort(vector<int>& array) {
	const int size = array.size();

	// Find the largest element of the array
	int mxValue = array[0];
	int minValue = array[0];
	for (int i = 1; i < size; ++i) {
		if (array[i] > mxValue) {
			mxValue = array[i];
		}
		if (array[i] < minValue) {
			minValue = array[i];
		}
	}

	const size_t diff = std::abs(mxValue - minValue);

	if (diff > LIMIT) {
		std::cout << "difference of min & max value is " << std::abs(mxValue - minValue)
				  << " which is greater than " << LIMIT << std::endl;
		return;
	}

	// Compute Frequency
	vector<int> count(diff + 1);	// zeros
	for (int i = 0; i < size; ++i)
		count[std::abs(array[i] - minValue)] += 1;

	// Put the values back to the array
	int idx = 0;
	for (int i = 0; i <= diff; ++i) {
		for (int j = 0; j < count[i]; ++j, ++idx)
			array[idx] = i + minValue;
	}
}

int main() {
	std::vector<int> nums = { 10'000'107, 10'000'035, 10'000'001 };
	countSort(nums);

	for (int num : nums) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}