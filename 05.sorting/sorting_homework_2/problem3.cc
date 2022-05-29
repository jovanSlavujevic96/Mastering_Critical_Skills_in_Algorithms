/***
* Problem #3: LeetCode 561 - Array Partition I
*
* Given an integer array nums of 2n integers:
*   group these integers into n pairs (a1,b1), (a2,b2), ... , (an,bn)
*   such that the sum of min(ai,bi) for all i is maximized.
*   return the maximized sum
*
* int arrayPairSum(vector<int>& nums);
* Develop O(nlogn) time solution
*
* Terminology: An optimization problem is the problem of finding the best solution from all feasible
* solutions. It usually asks for the best minimum or maximum.
*
* Tip: Given an array of 2n numbers => implies the array has an even size
*   [1,2,3,4,5,6,7,8] => n = 4
*
* Examples
*
* Example 1:
* Input: nums = [1,4,2,3]
* Output: 4
* Explanation: All possible pairing (ignoring the ordering of elements) are:
* 1. (1,4), (2,3) -> min(1,4) + min(2,3) = 1 + 2 = 3
* 2. (1,3), (2,4) -> min(1,3) + min(2,4) = 1 + 2 = 3
* 3. (1,2), (3,4) -> min(1,2) + min(3,4) = 1 + 3 = 4
* So the maximum possible sum is 4.
*
* Example 2:
* Input: nums = [6,2,6,5,1,2]
* Output: 9
* Explanation: The optimal pairing is (2,1), (2,5), (6,6).
* min(2,1) + min(2,5) + min(6,6) = 1 + 2 + 6 = 9
**/

#include <iostream>
#include <vector>

#include <climits>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
	std::sort(nums.begin(), nums.end());

	int sum = 0;
	for (int i = 0; i < nums.size(); i += 2) {
		sum += nums[i];
	}

	return sum;
}

int main() {
	vector<int> input = { 1,4,2,3 };
	std::cout << "sum is: " << arrayPairSum(input) << std::endl;
	return 0;
}
