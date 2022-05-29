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

// MY WAY
void wiggleSort(vector<int>& nums) {
	for (size_t i = 0; i < nums.size() - 1; i++) {
		if (i % 2 == 0 && nums[i] > nums[i + 1]) {
			swap(nums[i], nums[i + 1]);
		}
		else if (i % 2 != 0 && nums[i] < nums[i + 1]) {
			swap(nums[i], nums[i + 1]);
		}
	}
}

// teahcer's way
#include <algorithm>

void wiggleSort1(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	for (size_t i = 1; i + 1 < nums.size(); i += 2) {
		swap(nums[i], nums[i + 1]);
	}
}

void wiggleSort2(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<int> ans; // O(n) extra memory
	
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		ans.push_back(nums[left]);
		if (left != right) {
			ans.push_back(nums[right]);
		}
		left += 1;
		right -= 1;
	}

	nums = std::move(ans);
}

int main() {
	//std::vector<int> input = { 3,5,2,1,6,4 };
	//std::vector<int> input = { 6,6,5,6,3,8 };
	std::vector<int> input = { 1,2,3,4,5,6,7,8 };

	// ME
	wiggleSort(input);

	for (int i : input) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	// TEACHER
	input = { 1,2,3,4,5,6,7,8 };
	
	wiggleSort1(input);

	for (int i : input) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	input = { 1,2,3,4,5,6,7,8 };

	wiggleSort2(input);

	for (int i : input) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}
