/*
* Homework 16: Grid Sum
*
* Given a 2D array of nums, all of them are positive distinct. Robot start
* from (0,0). It can move to the right of left or diagonal. It will select
* one direction: the maximum. Print the total path sum of this robot
*
* int path_sum(int grid[100][100], int row, int col, int ROWS, int COLS);
*
* Input (3 x 3)
* 1 7 8
* 2 10 11
* 20 5 9
*
* Output: 31 (from 1 + 10 + 11 + 9)
*   Robot start at (0,0). 3 possible values (2, 7, 10). Max 10, so go to this cell
*   Then 3 possible values (5, 9, 11). Go to 11. Then only 9 available.
*/

#include <iostream>

// MY WAY
int biggestIndex(int one, int two, int three) {
	if (one >= two && one >= three) {
		return 0;
	}
	else if (two >= one && two >= three) {
		return 1;
	}
	else {
		return 2;
	}
}

template <int I, int J>
int path_sum(int grid[I][J], int row, int col) {
	const int& singleGrid = grid[row][col];
	const unsigned short option = (row + 1 == I) | (col + 1 == J) << 8;

	switch (option) {
	case 0x0101:
		return singleGrid;
	case 0x0001: // (row + 1 == I)
		col++;
		break;
	case 0x0100: // (col + 1 == J)
		row++;
		break;
	default:
		switch (biggestIndex(grid[row + 1][col], grid[row][col + 1], grid[row + 1][col + 1])) {
		case 0:
			row++;
			break;
		case 1:
			col++;
			break;
		default:
			row++;
			col++;
		}
	}
	return singleGrid + path_sum<I,J>(grid, row, col);
}

// TEACHER'S WAY
int di[] = { 1,0,1 };
int dj[] = { 0,1,1 };

int teach_path_sum(int grid[100][100], int ROWS, int COLS, int row = 0, int col = 0) {
	int sum = grid[row][col];

	if (row == ROWS - 1 && col == COLS - 1) {
		return sum;
	}

	int max_idx = -1;
	int max_value = 0;

	for (int d = 0; d < 3; ++d) {
		int new_row = row + di[d];
		int new_col = col + dj[d];

		if (new_row >= ROWS || new_col >= COLS) {
			continue;
		}

		if (max_value < grid[new_row][new_col]) {
			max_value = grid[new_row][new_col];
			max_idx = d;
		}
	}
	int new_row = row + di[max_idx];
	int new_col = col + dj[max_idx];

	return sum + teach_path_sum(grid, ROWS, COLS, new_row, new_col);
}

int main() {
	int grid[3][3] = {
		1, 7, 8,
		2, 10, 11,
		20, 5, 9
	};
	std::cout << "PATH SUM is " << path_sum<3,3>(grid, 0, 0) << std::endl;
	return 0;
}
