#include <assert.h>
#include <iostream>



int count(int[], int, int);
int myLinearSearch(int[], int, int);
void myCountAlpha(const char*);
int myBinarySearch(int[], int, int);

int count(int arr[], int size, int n)
{
	int result = 0;

	for (int i = 0; i < size; ++i)
	{
		if (*arr++ == n)
		{
			++result;
		}
	}

	return result;
}

int myLinearSearch(int arr[], int size, int n)
{
	for (int i = 0; i < size; ++i)
	{
		if (*arr++ == n)
		{
			return i;
		}
	}

	return -1;
}

void myCountAlpha(const char* str)
{
	assert(str != nullptr);
	int counts[26] = { 0, };

	while (*str != '\0')
	{
		assert(97 <= *str && *str <= 123);

		counts[*str++ - 97]++;
	}

	int size = sizeof(counts) / sizeof(counts[0]);
	for (int i = 0; i < size; ++i)
	{
		if (counts[i] > 0)
		{
			std::cout << ((char)(97 + i)) << counts[i];
		}
	}

	std::cout << std::flush;
}

int myBinarySearch(int arr[], int size, int n)
{
	if (size == 0)
	{
		return -1;
	}

	int minIndex = 0;
	int maxIndex = size - 1;
	int midIndex = (minIndex + maxIndex) / 2;

	while (minIndex <= midIndex && midIndex <= maxIndex)
	{
		if (arr[midIndex] == n)
		{
			return midIndex;
		}

		if (arr[midIndex] < n)
		{
			minIndex = midIndex + 1;
		}
		else
		{
			maxIndex = midIndex - 1;
		}

		midIndex = (minIndex + maxIndex) / 2;
	}

	return -1;
}

//
