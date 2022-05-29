/***
* Problem #5: LeetCode 1921 - Eliminate Maximum Number of Monsters
*
* You are playing a video game where you are defending your city from a group of n monsters. You are
* given a 0-indexed integer array dist of size n, where dist[i] is the initial distance in kilometers of the
* i-th monster from the city.
*
* The monsters walk toward the city at a constant speed. The speed of each monster is given to you in an
* integer array speed of size n, where speed[i] is the speed of the i-th monster in kilometers per minute.
*
* You have a weapon that, once fully charged, can eliminate a single monster. However, the wapon takes one minut
* to charge. The weapon is full charged at the very start.
*
* You lose when anu monster reaches your city. If a monster reaches the city at the exact moment the wapon
* is fully charged, it counts as a loss, and the game ends before you can use your weapon.
*
* Return the maximum number of monsters that you can eliminate before you lose, or n if you can eliminate
* all the monsters before they reach the city.
*
* int eliminateMaximum(vector<int>& dist, vector<int>& speed);
*
* Example 1:
*   Input: dist = [1,3,4], speed = [1,1,1]
*   Output: 3
*   Explanation:
*
*   In the beginnning, the distances of the monsters are [1,3,4]. You eliminate the first monster.
*   After a minute, the distances of the monsters are [X,2,3]. You eliminate the second monster.
*   After a minute, the distances of the monsters are [X,X,2]. You eliminate the third monster.
*   All 3 monsters can be eliminated.
*
* Example 2:
*   Input: dist = [1,1,2,3], speed = [1,1,1,1]
*   Output: 1
*   Explanation:
*
*   In the beginning, the distances of the monsters are [1,1,2,3]. You eliminate the first monster.
*   After a minute, the distances of the monsters are [X,0,1,2], so you lose.
*   You can only eliminate 1 monster.
*
* Example 3:
*   Input: dist = [3,2,4], speed = [5,3,2]
*   Output: 1
*   Explanation:
*
*   In the beginning, the distances of the monsters are [3,2.4]. You eliminate the first monster.
*   After a minute, the distances of the monster are [X,0,2], so you lose.
*   You can only eliminate 1 monster.
*
* Can you code such that there are no double conversion (e.g.division)
* or modulus operator ?
**/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// MY WAY - BAD
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
	/*for (int i = 1; i < dist.size(); i++) {
		for (int j = i; j - 1 >= 0 && dist[j] < dist[j - 1]; j++) {
			std::swap(dist[j], dist[j - 1]);
			std::swap(speed[j], speed[j - 1]);
		}
	}*/

	int count = 0;
	for (int i = 0; i < dist.size(); i++) {
		int nearestIdx = i;
		int nearestDistance = INT_MAX;
		for (int j = i; j < dist.size(); j++) {
			int distance = dist[j] - speed[j] * i;
			if (distance <= 0) {
				// I'M DEAD
				return count;
			}
			distance -= speed[j];
			if (distance < nearestDistance) {
				// I'LL CONSIDER KILLING HIM
				nearestDistance = distance;
				nearestIdx = j;
			}
		}
		if (nearestIdx != i) {
			std::swap(dist[i], dist[nearestIdx]);
			std::swap(speed[i], speed[nearestIdx]);
		}
		count++;
	}
	return count;
}

// teahcer's way

#include <algorithm>

static bool cmp_arrival_time(const pair<int, int>& a, const pair<int, int>& b) {
	// a/b < c/d. Multiply all sides with bd ==> ad < bc
	//return a.first / double(a.second) < b.first / double(b.second);
	return a.first * b.second < a.second* b.first;
}

int teach_eliminateMaximum(vector<int>& dist, vector<int>& speed) {
	const int sz = dist.size();
	int killed = 0;
	vector<pair<int, int>> arrival_time;

	for (int i = 0; i < sz; i++) {
		arrival_time.push_back({ dist[i], speed[i] });
	}

	sort(arrival_time.begin(), arrival_time.end(), cmp_arrival_time);

 	for (int t = 0; t < sz; ++t) {
		if (arrival_time[t].second * t >= arrival_time[t].first)
			break;	// speed*t (covered distance) >= how far: we can;t
		killed++;
	}
	return killed;
}

int main() {
	//vector<int> distance = { 1,3,4 };
	//vector<int> speed = { 1,1,1 };

	//vector<int> distance = { 1,1,2,3 };
	//vector<int> speed = { 1,1,1,1 };

	//vector<int> distance = { 6,9,6,7,9,7,10,6,6,7 };
	//vector<int> speed =    { 1,1,1,1,2,1, 2,1,1,2 };

	//vector<int> distance = { 8,5,7,8,5,6,10,8,5 };
	//vector<int> speed    = { 4,1,2,5,1,1, 2,1,1 };

	vector<int> distance =
	{
		46, 33, 44, 42, 46, 36,  7, 36, 31, 47, 38, 42, 43, 48, 48, 25, 28, 44, 49, 47, 29, 32, 30,
		 6, 42,  9, 39, 48, 22, 26, 50, 34, 40, 22, 10, 45,  7, 43, 24, 18, 40, 44, 17, 39, 36
	};
	vector<int> speed =
	{
		 1,  2,  1,  3,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  7,  1,  1,  3,  2,  2,  2,  1,  2,
		 1,  1,  1,  1,  1,  1,  1,  1,  6,  1,  1,  1,  8,  1,  1,  1,  3,  6,  1,  3,  1,  1
	};

	std::cout << "You can eliminate: " << teach_eliminateMaximum(distance, speed) << " monster(s).\n";
	return 0;
}