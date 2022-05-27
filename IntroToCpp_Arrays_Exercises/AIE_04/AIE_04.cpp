#include <iostream>


void SortArray(int* arr, int count);
bool IsArraySorted(const int* arr, int count);
//establishes array sorts it and checks if sort has worked
int main(int argc, char** argv)
{
	const int NUM_ITEMS = 8;
	int numbers[NUM_ITEMS] = { 13, 1, 7, 5, 11, 9, 15, 3 };

	SortArray(numbers, NUM_ITEMS);

	// Test: all values should be sorted in ascending order
	if (IsArraySorted(numbers, NUM_ITEMS)) std::cout << "Pass: the array is sorted" << std::endl;
	else std::cout << "Fail: the array is not sorted" << std::endl;

	return 0;
}
//checks if array is sorted in ascending order if 1 item is out of order returns false
bool IsArraySorted(const int* arr, int count)
{	
	for (int i = 0; i < count - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

//bubble sort in ascending order
void SortArray(int* arr, int count)
{
	// TODO: 
	// modify the values in the array so that when this method returns
	// all values are sorted in ascending order
	if (count <= 1) {
		return;
	}
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < count - 1; i++)
		{
			if (arr[i] > arr[i + 1]) {
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = false;
			}
		}
	}
}
