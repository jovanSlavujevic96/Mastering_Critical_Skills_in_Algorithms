/***
* Problem #2: LeetCode 976 - Largest Perimeter Triangle
*
* Given an integer array nums, return the largest perimeter of a triangle with a
* non-zero area, formed from three of these lenghts.
*   If it is impossible to form any triangle of a non-zero area, return 0.
*
* Review what makes a triangle a valid one
* int largestPerimeter(vector<int>& nums)
*   Array size >= 3
*
* Example 1:
*  Input: nums = [2,1,2]
*  Output: 5
*
* Example 2:
*  Input: nums = [1,2,1]
*  Output: 0
*
* NOTE: all combinations of sum of two sides must be grater than third side
* in order to be a non-zero area
*
* Develop O(nlogn) time solution
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// MY WAY - Bad perfromance on LeetCode
int largestPerimeter(vector<int>& nums) {
	// sort
	std::sort(nums.begin(), nums.end());
	
	// find largestP
	int largestP = 0;
	for (int i = 0; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				if (nums[i] + nums[j] > nums[k]) {
					largestP = std::max(largestP, nums[i] + nums[j] + nums[k]);
				}
			}
		}
	}
	return largestP;
}

// teacher's way
int teach_largestPerimeter(vector<int>& nums) {
	// largest -> smallest
	sort(nums.rbegin(), nums.rend());

	for (int i = 0; i < nums.size() - 2; i++) {
		// one check is enough as they are sorted. Otherwise 3 validations
		if (nums[i] < nums[i + 1] + nums[i + 2]) {
			return nums[i] + nums[i + 1] + nums[i + 2];
		}
	}
	return 0;
}

int main() {
	std::vector<int> input = { 3,6,2,3 };
	std::cout << "largest perimeter is: " << teach_largestPerimeter(input) << std::endl;
	return 0;
}
