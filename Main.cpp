// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#include <iostream>
#include <assert.h>

using namespace std;

void mySwap(int&, int&);
void mySort(int[], int);
void mySelectionSort(int[], int);
bool CheckSorted(int[], int);

int main(void)
{
	int arr[10] = { 5, 3, 7, 6, 8, 9, 10, 4, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	assert(CheckSorted(arr, size) == false);
	mySelectionSort(arr, size);
	assert(CheckSorted(arr, size) == true);
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

int indexOfMin(int arr[], int size, int start)
{
	int minIndex = start;

	for (int i = start; i < size; ++i)
	{
		if (arr[i] < arr[minIndex])
		{
			minIndex = i;
		}
	}

	return minIndex;
}

void mySelectionSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int minIndex = indexOfMin(arr, size, i);

		if (minIndex != i)
		{
			mySwap(arr[i], arr[minIndex]);
		}
	}
}
