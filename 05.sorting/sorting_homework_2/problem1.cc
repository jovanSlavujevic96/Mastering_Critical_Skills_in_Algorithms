/***
* Problem #1 : LeetCode 1200 - Minimum Absoulte Difference
*
* Given an array of distinct integers arr, find all pair of
* elements with the minimum absoulte difference of any two elements.
*
* Return a list of pair in ascending order (with respect to pairs),
* each pair [a, b] follows
*   a, b are from arr
*   a < b
*   b - a equals to the minimum absolute difference of any two eelemnts in arr
*
* vector<vector<int>> minimumAbsDifference(vector<int>& nums)
* Develop an O(nlogn) time solution
*
* Examples
* Example 1:
*   Input: arr = [4,2,1,3]
*   Output: [[1,2],[2,3],[3,4]]
*   Explanation: The minimum absoulte difference is 1. List al pairs with
*   difference equal to 1 in ascending order
*
* Example 2:
*   Input: arr = [1,3,6,10,15]
*   Output: [[1,3]]
*
* Example 3:
*   Input: arr = [3,8,-10,23,19,-4,-14,27]
*   Output: [[-14,-10],[19,23],[23,27]]
**/

#include <iostream>
#include <vector>

#include <algorithm>
#include <climits>

using namespace std;

// MY SOLUTION - Bad performance on LeetCode
vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
	vector<vector<int>> out;

	// find smallest difference
	int smallest_diff = std::abs(nums[0] - nums[1]);
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			int diff = std::abs(nums[i] - nums[j]);
			if (diff < smallest_diff) {
				smallest_diff = diff;
			}
		}
	}

	// insert pairs
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			int diff = nums[i] - nums[j];
			if (diff * -1 == smallest_diff) {
				out.push_back({ nums[i] , nums[j] });
			}
			else if (diff == smallest_diff) {
				out.push_back({ nums[j], nums[i] });
			}
		}
	}

	// sort pairs - INSERTION SORT
	for (int i = 1; i < (int)out.size(); i++) {
		for (int j = i; (j - 1 >= 0) && (out[j][0] < out[j - 1][0]); j--) {
			std::swap(out[j], out[j - 1]);
		}
	}

	return out;
}

// teacher's way
// O(nlogn) time complexity
// O(1) space complexity 
vector<vector<int>> teach_minimumAbsDifference(vector<int>& arr) {
	// sort array
	std::sort(arr.begin(), arr.end());

	int min_diff = INT_MAX; // compute min absolute
	for (int i = 1; i < arr.size(); i++) {
		min_diff = std::min(min_diff, arr[i] - arr[i - 1]);
	}

	// Find consecuite values with that min diff
	vector<vector<int>> res;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] - arr[i - 1] == min_diff) {
			res.push_back({ arr[i - 1], arr[i] });
		}
	}

	return res;
}

int main() {
	//std::vector<int> input = { 4,2,1,3 };
	//std::vector<int> input = { 1,3,6,10,15 };
	std::vector<int> input = { 3,8,-10,23,19,-4,-14,27 };

	auto output = teach_minimumAbsDifference(input);

	for (std::vector<int>& out : output) {
		for (int n : out) {
			std::cout << n << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}