#include <assert.h>


int myRecursionSum(int[], int);
int myFibo(int);
int myFibo2(int);
int myBinarySearchRecursive(int[], int, int, int);
void myPermutation(int[], int);


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