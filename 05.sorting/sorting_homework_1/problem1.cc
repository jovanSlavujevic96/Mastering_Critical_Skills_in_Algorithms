/***
* Problem #1: Insertion Sort v2
*
* Introduce these changes to the lecture code
* 1) Sort the data in descending order
* 2) Utilize the swap function to reduce the code length
*    Your new code should be only 3 lines
* Which one has fewer number of operations: this version vs the lecture ?
**/

#include <iostream>
#include <vector>
#include <cstdint>

void insertion_sort(std::vector<int>& nums) {
	for (int i = 1; i < (int)nums.size(); i++) {
		for (int j = i; (j - 1 >= 0) && (nums[j] > nums[j - 1]); j--) {
			std::swap(nums[j], nums[j - 1]);
		}
	}
}

int main() {
	std::vector<int> nums = { 1,2,3 };
	insertion_sort(nums);

	for (int num : nums) {
		std::cout << num << ' ';
	}
	std::cout << std::endl;
	return 0;
}