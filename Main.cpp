#include <iostream>
#include <assert.h>

using namespace std;

void mySwap(int&, int&);
bool CheckSorted(int[], int);
// sort
void mySort(int[], int);
void mySelectionSort(int[], int);
void myBubbleSort(int[], int);
void myInsertionSort(int[], int);
// search
int count(int[], int, int);
int myLinearSearch(int[], int, int);
void myCountAlpha(const char*);
int myBinarySearch(int[], int, int);
// recursion
int myRecursionSum(int[], int);
int myFibo(int);
int myFibo2(int);
int myBinarySearchRecursive(int[], int, int, int);
void myPermutation(int[], int);

int main(void)
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	assert(myBinarySearch(arr, 10, 10) == 9);
	assert(myBinarySearchRecursive(arr, 0, 9, 10) == 9);

	assert(myBinarySearch(arr, 10, 11) == -1);
	assert(myBinarySearchRecursive(arr, 0, 9, 11) == -1);
}

void mySwap(int& n1, int& n2)
{
	n1 = n1 ^ n2;
	n2 = n1 ^ n2;
	n1 = n1 ^ n2;
}

bool CheckSorted(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}

	return true;
}

void mySort(int arr[], int size)
{
	for (int j = 0; j < size - 1; ++j)
	{
		for (int i = 0; i < size - 1 - j; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				mySwap(arr[i], arr[i + 1]);
			}
		}
	}
}

void mySelectionSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			mySwap(arr[i], arr[minIndex]);
		}
	}
}

void myBubbleSort(int arr[], int size)
{
	bool sorted;
	
	for (int i = 0; i < size - 1; ++i)
	{
		sorted = true;

		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				mySwap(arr[j], arr[j + 1]);
				sorted = false;
			}
		}

		if (sorted)
		{
			return;
		}
	}
}

void myInsertionSort(int arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int temp = arr[i];
		
		int j = i;
		while (j > 0 && arr[j - 1] > temp)
		{
			arr[j] = arr[j - 1];
			--j;
		}

		arr[j] = temp;
	}
}

//

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
			cout << ((char) (97 + i)) << counts[i];
		}
	}

	cout << flush;
}

int myBinarySearch(int arr[], int size, int n)
{
	assert(CheckSorted(arr, size));
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

int myRecursionSum(int arr[], int n)
{
	if (n == 0)
	{
		return arr[0];
	}

	return arr[n] + myRecursionSum(arr, n - 1);
}

int myFibo(int n)
{
	if (n <= 1)
	{
		return n;
	}

	return myFibo(n - 1) + myFibo(n - 2);
}

int myFibo2(int n)
{
	assert(n >= 0);

	if (n <= 1)
	{
		return n;
	}
	
	int arr[2] = { 0, 1 };

	for (int i = 0; i < n - 2; ++i) 
	{
		int temp = arr[1];
		
		arr[1] += arr[0];
		arr[0] = temp;
	}

	return arr[0] + arr[1];
}

int myBinarySearchRecursive(int arr[], int start, int end, int n)
{
	if (start > end)
	{
		return -1;
	}

	int mid = (start + end) / 2;
	if (arr[mid] == n)
	{
		return mid;
	}
	else if (arr[mid] < arr[end])
	{
		myBinarySearchRecursive(arr, mid + 1, end, n);
	}
	else
	{
		myBinarySearchRecursive(arr, start, mid - 1, n);
	}
}

void myPermutation(int arr[], int start, int end)
{
	assert(start >= 0);
	assert(end >= 0);
	assert(arr != nullptr);

	if (start > end)
	{
		return;
	}

	// [1, 2, 3, 4]
	// 1
	// 2
	// 3
	// 4
	// 1, 2
	// 1, 3
	// 1, 4
	// 2, 3
	// 2, 4
	// 3, 4
	// 1, 2, 3,
	// 1, 2, 4
	// 1, 3, 4
	// 2, 3, 4
	// 1, 2, 3, 4
}