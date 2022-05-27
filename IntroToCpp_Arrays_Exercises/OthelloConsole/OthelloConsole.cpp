#include <iostream>
#include <vector>

/*
You are required to implement the IsValidMove method for an 'Othello' game.
ALL TESTS CASES MUST PASS.

You are required to implement the MakeMove method for an Othello Game
ALL TEST CASES MUST PASS

*/

typedef std::vector<std::vector<char>> OthelloBoardState;

bool IsValidMove(char player, int col, int row, const OthelloBoardState& grid);
OthelloBoardState MakeMove(char player, int col, int row, OthelloBoardState grid);


int main(int argc, char** argv)
{
	OthelloBoardState state1 =
	{//   0    1    2    3    4    5    6    7
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 1
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 2
		{' ', ' ', ' ', 'W', 'B', ' ', ' ', ' '}, // 3
		{' ', ' ', ' ', 'B', 'W', ' ', ' ', ' '}, // 4
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
	};

	auto ShouldBe = [](auto result, auto expected) {
		std::cout << (result == expected ? "\033[32m [PASS]" : "\033[31m [FAIL]") << "\033[0m" << std::endl;
	};


	ShouldBe(IsValidMove('B', 5, 4, state1), true);  // true
	ShouldBe(IsValidMove('B', 2, 4, state1), false); // false
	ShouldBe(IsValidMove('B', 3, 2, state1), true);  // true
	ShouldBe(IsValidMove('B', 3, 5, state1), false); // false
	ShouldBe(IsValidMove('B', 5, 5, state1), false); // false
	ShouldBe(IsValidMove('W', 5, 4, state1), false); // false
	ShouldBe(IsValidMove('W', 2, 4, state1), true);  // true
	ShouldBe(IsValidMove('W', 3, 2, state1), false); // false
	ShouldBe(IsValidMove('W', 3, 5, state1), true);  // true
	ShouldBe(IsValidMove('W', 5, 5, state1), false); // false

	OthelloBoardState state2 =
	{//   0    1    2    3    4    5    6    7
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
		{' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '}, // 1
		{' ', ' ', 'B', 'W', ' ', ' ', ' ', ' '}, // 2
		{' ', ' ', 'B', 'W', 'B', ' ', ' ', ' '}, // 3
		{' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '}, // 4
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
	};
	std::cout << std::endl;
	ShouldBe(IsValidMove('B', 2, 5, state2), true);  // true
	ShouldBe(IsValidMove('B', 3, 5, state2), false); // false
	ShouldBe(IsValidMove('B', 4, 5, state2), true);  // true
	ShouldBe(IsValidMove('B', 3, 1, state2), false); // false
	ShouldBe(IsValidMove('B', 4, 2, state2), true);  // true
	ShouldBe(IsValidMove('B', 4, 1, state2), true);  // true
	ShouldBe(IsValidMove('W', 2, 5, state2), false); // false
	ShouldBe(IsValidMove('W', 2, 0, state2), true);  // true
	ShouldBe(IsValidMove('W', 3, 1, state2), false); // false

	return 0;
}
bool IsAdjacent(char player, int col, int row, const OthelloBoardState& grid) {
	char enemy;
	if (player == 'B') {
		enemy = 'W';
	}
	else enemy = 'B';
	if ((grid[row + 1][col] == enemy && grid[row][col] == ' ') ||
		(grid[row - 1][col] == enemy && grid[row][col] == ' ') ||
		(grid[row][col + 1] == enemy && grid[row][col] == ' ') ||
		(grid[row][col - 1] == enemy && grid[row][col] == ' ') ||
		(grid[row - 1][col - 1] == enemy && grid[row][col] == ' ') ||
		(grid[row - 1][col + 1] == enemy && grid[row][col] == ' ') ||
		(grid[row + 1][col - 1] == enemy && grid[row][col] == ' ') ||
		(grid[row + 1][col + 1] == enemy && grid[row][col] == ' ')
		)
	{
		return true;
	}
	return false;
}

bool CheckVertical(char player, int col, int row, const OthelloBoardState& grid) {
	char enemy;
	//to stop out of range exception check for 0 or max values in  and dont tes
	if (player == 'B') {
		enemy = 'W';
	}
	else enemy = 'B';

	/*if ((grid[row][col] == ' ' && grid[row + 1][col] == enemy) || (grid[row - 1][col] == enemy && grid[row][col] == ' '))
	{
		return true;
	}*/
	if (row == 0) {
		if ((grid[row + 1][col] == enemy && grid[row][col] == ' ')) {
			for (int i = row; i != grid[row].size(); i++)
			{
				if (grid[i][col] == player)
				{
					return true;
				}
			}
			return false;
		}
	}
	else if (row == 8) {
		if ((grid[row][col] == ' ' && grid[row - 1][col] == enemy)) {
			for (int i = row; i != 0; i--)
			{
				if (grid[i][col] == player)
				{
					return true;
				}
			}
			return false;
		}
	}
	else {
		if ((grid[row][col] == ' ' && grid[row - 1][col] == enemy)) {
			for (int i = row; i != 0; i--)
			{
				if (grid[i][col] == player)
				{
					return true;
				}
			}
			return false;
		}
		else if ((grid[row + 1][col] == enemy && grid[row][col] == ' ')) {
			for (int i = row; i != grid[row].size(); i++)
			{
				if (grid[i][col] == player)
				{
					return true;
				}
			}
			return false;
		}
	}
	return false;
}
bool CheckHorizontal(char player, int col, int row, const OthelloBoardState& grid) {
	char enemy;
	if (player == 'B') {
		enemy = 'W';
	}
	else enemy = 'B';
	if (col == 0) {
		if ((grid[row][col + 1] == enemy && grid[row][col] == ' ')) {
			for (int i = col; i != grid[row].size() + 1; i++)
			{
				if (grid[row][i] == player)
				{
					return true;
				}
			}
			return false;
		}
	}
	else if (col == 8) {
		if ((grid[row][col] == ' ' && grid[row][col - 1] == enemy)) {
			for (int i = col; i != 0; i--)
			{
				if (grid[row][i] == player)
				{
					return true;
				}
			}
			return false;
		}
	}
	else {
		if ((grid[row][col] == ' ' && grid[row][col - 1] == enemy)) {
			for (int i = col; i != 0; i--)
			{
				if (grid[row][i] == player)
				{
					return true;
				}
			}
			return false;
		}
		else if ((grid[row][col + 1] == enemy && grid[row][col] == ' ')) {
			for (int i = col; i != grid[row].size() + 1; i++)
			{
				if (grid[row][i] == player)
				{
					return true;
				}
			}
			return false;
		}
	}
	return false;
}
bool CheckDiagonal(char player, int col, int row, const OthelloBoardState& grid) {
	char enemy;
	if (player == 'B') {
		enemy = 'W';
	}
	else enemy = 'B';
	bool adj = IsAdjacent(player, col, row, grid);
	if ((grid[row + 1][col + 1] == enemy && grid[row][col] == ' ' && adj) ||
		(grid[row + 1][col - 1] == enemy && grid[row][col] == ' ' && adj) ||
		(grid[row - 1][col + 1] == enemy && grid[row][col] == ' ' && adj) ||
		(grid[row - 1][col - 1] == enemy && grid[row][col] == ' ' && adj))
	{
		return true;
	}
	return false;
}

bool IsValidMove(char player, int col, int row, const OthelloBoardState& grid)
{
	// Task 1:
	// this method should return true if the 'player'
	// can be placed on the grid at the specified row/col location.


	if (CheckHorizontal(player, col, row, grid) || CheckVertical(player, col, row, grid) || CheckDiagonal(player, col, row, grid))
	{
		return true;
	}
	return false;

}
int Clamp(int min, int max, int value) {
	if (value > max) {
		value = max;
	}
	else if (value < min) {
		value = min;
	}
	else return value;
}

OthelloBoardState MakeMove(char player, int col, int row, OthelloBoardState grid)
{
	// if the move was not valid, just return the original...
	if (IsValidMove(player, col, row, grid) == false)
		return grid;

	// Task 2:
	// Implement the make move method
	// The method should alter the 'grid' variable, and return it as a copy
	// taht represets the new board state

	return grid;
}