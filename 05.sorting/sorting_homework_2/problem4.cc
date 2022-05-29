/***
* Problem #4: LeetCode 280 - Wiggle Sort
*
* Give an integer array nums, reorder it such that
* nums[0] <= nums[1] >= nums[2] <= nums[3]
*
* void wiggleSort(vector<int>& nums);
*   You may assume the input array always has a valid answer.
*   Develop O(nlogn) time solution.
*
* Input => Output
*   [3,5,2,1,6,4] => [3,5,1,6,2,4] or [1,6,2,5,3,4]
*   [6,6,5,6,3,8] => [6,6,5,6,3,8]
*
* It is guaranteed that there will be an answer for the given input nums.
*   So don't build an invalid test case for yourself
**/

#include <iostream>
#include <vector>

using namespace std;

//  3  5  2  1  6  4
// [3  5] 2  1  6  4  // lower
//  3 [5  2] 1  6  4  // bigger
//  3  5 [2  1] 6  4  // lower
//  3  5 [1  2] 6  4  // lower
//  3  5  1 [2  6] 4  // bigger
//  3  5  1 [6  2] 4  // bigger
//  3  5  1  6 [2  4] // lower

void wiggleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		if (i % 2 == 0 && nums[i] > nums[i + 1]) {
			swap(nums[i], nums[i + 1]);
		}
		else if (i % 2 != 0 && nums[i] < nums[i + 1]) {
			swap(nums[i], nums[i + 1]);
		}
		continue;
	}
}

int main() {
	std::vector<int> input = { 3,5,2,1,6,4 };
	//std::vector<int> input = { 6,6,5,6,3,8 };
	wiggleSort(input);

	for (int i : input) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}
