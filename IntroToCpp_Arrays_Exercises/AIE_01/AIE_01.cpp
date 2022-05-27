
#include <iostream>

int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 5;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50 };

	/*
	TODO: Print the index and value of each number in the above array
	Expected:
		0: 10
		1: 20
		2: 30
		3: 40
		4: 50
	*/
	// Task1: Write your Code here
	// ------------------------------------------------------------------------
	for (int i = 0; i < NUM_NUMBERS ; i++)
	{
		std::cout << i << ": " << numbers[i] << std::endl;
	}
	// ------------------------------------------------------------------------


	/*
	TODO: print the index and value of each number in reverse order
	Expected:
		4: 50
		3: 40
		2: 30
		1: 20
		0: 10
	*/

	// Task 2: Write your Code here
	// ------------------------------------------------------------------------
	for (int i = NUM_NUMBERS - 1; i >= 0; i--)
	{
		std::cout << i << ": " << numbers[i] << std::endl;
	}
	// ------------------------------------------------------------------------

	return 0;
}
