
#include <iostream>

int MinValue(const int* arr, int count);
int MaxValue(const int* arr, int count);
int CountOccurencesOfValue(const int* arr, int count, int search);


int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 10;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50, 10, 20, 30, 40, 50 };

	// In C++, an array is simply a pointer to the first value
	// when passing an array through a function parameter, we loose the length information
	// therefore we need to pass the array size in as well

	// implement the above methods
	// so that the expected output is printed to the console

	std::cout << "Expected: 10 - Got: " << MinValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 50 - Got: " << MaxValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 2 - Got: " << CountOccurencesOfValue(numbers, NUM_NUMBERS, 10) << std::endl;
	std::cout << "Expected: 0 - Got: " << CountOccurencesOfValue(numbers, NUM_NUMBERS, 8) << std::endl;

	return 0;
}

//returns minimum value in the array
int MinValue(const int* arr, int count)
{
	int minval = INT_MAX;
	for (int i = 0; i < count; i++)
	{
		if (arr[i] < minval)
		{
			minval = arr[i];
		}
	}
	return minval;
}
//returns max value in the array
int MaxValue(const int* arr, int count)
{
	int maxval = INT_MIN;
	for (int i = 0; i < count; i++)
	{
		if (arr[i] > maxval)
		{
			maxval = arr[i];
		}
	}
	return maxval;
}
// counts how many times an instance occurs inside of an array
int CountOccurencesOfValue(const int* arr, int count, int search)
{
	int occur = 0;
	for (int i = 0; i < count; i++)
	{
		if (arr[i] == search)
		{
			occur++;
		}
	}
	return occur;
}

