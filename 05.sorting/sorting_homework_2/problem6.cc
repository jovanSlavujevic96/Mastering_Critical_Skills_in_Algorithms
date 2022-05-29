/***
* Problem #6: LeetCode 1005 - Maximize Sum of Array After K negotiations
* 
* Given an integer array nums and an integer k, modify the array in the following way:
*   choose an index i and replace nums[i] with -nums[i].
*   You should apply this process exactly k times.
* You may choose the same index i multuple times.
* Return the largest possible sum of the array after modifying it in this way.
* 
* int largestSumAfterKNegotiations(vector<int>& nums, int k)
*
* Example 1:
* Input: nums = [4, 2, 3], k = 1
* Output: 5
* Explanation: Choose index 1 and nums becomes [4, -2, 3].
* 
* Example 2:
* Input: nums = {3,-1,0,2}, k = 3
* Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
*
* Example 3:
* Input: nums = {2,-3,-1,5,-4}, k = 2
* Output: 13
* Explanation: Choose indices (1,4) and nums becomes [2,3,-1,5,4]
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int largestSumAfterKNegotiations(vector<int>& nums, int k) {
	// if k is odd  number & there are no negative nums => reach   the smallest number and do it k times
	// if k is even number & there are no negative nums => reach the any number and do it k times
	// if k is odd  number & there are negative nums    => convert the smallest negative nums
	// if k is even number & there are negative nums    => convert the smallest negative nums
	
	sort(nums.begin(), nums.end());

	const size_t size = nums.size();
	size_t smallestIdx = 0;
	int sum = 0;

	for (size_t i = 0; i < size - 1; i++) {
		if (k != 0 && nums[i] < 0) {
			nums[i] *= -1;

			k--;
		}

		if (nums[i + 1] < nums[smallestIdx]) {
			smallestIdx = i + 1;
		}

		sum += nums[i];
	}

	if (k % 2 != 0) {
		nums[smallestIdx] *= -1;
		if (smallestIdx != size - 1) {
			sum += 2 * nums[smallestIdx];
		}
	}

	sum += nums.back();

	return sum;
}

int main() {
	//std::vector<int> input = { 4, 2, 3 };
	//int k = 1; // expects 5

	//std::vector<int> input = { 5,6,9,-3,3 };
	//int k = 2; // expects 20

	//std::vector<int> input = { -8,3,-5,-3,-5,-2 };
	//int k = 6; // expects 22

	//std::vector<int> input = { -4,-2,-3 };
	//int k = 4; // expects 5

	//std::vector<int> input = { -2,5,0,2,-2 };
	//int k = 3; // expects 11

	std::vector<int> input = { 4,-5,4,-5,9,4,5 };
	int k = 1; // expects 26

	std::cout << "largest sum after " << k << " negotiations is: " << largestSumAfterKNegotiations(input, k) << std::endl;
	return 0;
}
