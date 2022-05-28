/***
* Problem #2: Count Sort for Negative Values
*
* Develop a count sort version to handle the following requirements:
*   1 <= Array length <= 50'000
*   Values range: -50'000 <= nums[i] <= 50'000
* Input : nums = [-5,2,-3,1,1234,-2453]
* Output:        [-2453,-5,-3,1,2,1234]
* Online judge: LeetCode 912 - Sort an Array
*   Refer to the online judge section to understand about Online Judges and how to use
**/

#include <iostream>
#include <vector>

// MY WAY
void countSort(std::vector<int>& array) {
	const int size = array.size();

	// Find the largest & smallest element of the array
	int maxValue = array[0];
	int minValue = array[0];
	int offset = 0;

	for (int i = 1; i < size; ++i) {
		if (array[i] > maxValue) {
			maxValue = array[i];
		}
		if (array[i] < minValue) {
			minValue = array[i];
		}
	}

	if (minValue < 0) {
		maxValue += minValue * -1;
		offset += minValue * -1;
	}

	// Compute Frequency
	std::vector<int> count((size_t)maxValue + 1); // zeros
	for (int i = 0; i < size; ++i) {
		count[(size_t)array[i] + offset] += 1;
	}

	// Put the values back to the array
	int idx = 0;
	for (int i = 0; i <= maxValue; ++i) {
		for (int j = 0; j < count[i]; ++j, ++idx)
			array[idx] = i - offset;
	}
}

// teacher's way
void sortArray(std::vector<int>& array) {
	// Find the largest element of the array
	int size = array.size();
	const int SHIFT = 50000;

	for (int i = 0; i < size; ++i)
		array[i] += SHIFT;

	int max = array[0];
	for (int i = 1; i < size; ++i)
		if (array[i] > max)
			max = array[i];

	std::vector<int> count(max + 1);	// zeros

	// Compute Frequency
	for (int i = 0; i < size; ++i)
		count[array[i]] += 1;

	int idx = 0;
	for (int i = 0; i <= max; ++i) {
		for (int j = 0; j < count[i]; ++j, ++idx)
			array[idx] = i - SHIFT;
	}
}

int main() {
	{
		std::vector<int> nums = { -5,2,-3,1,1234,-2453 };
		countSort(nums);

		// MY WAY
		for (int num : nums) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
	{
		std::vector<int> nums = { -5,2,-3,1,1234,-2453 };
		sortArray(nums);

		// TEACHER'S WAY
		for (int num : nums) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
