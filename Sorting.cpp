void mySwap(int&, int&);
bool CheckSorted(int[], int);
void mySort(int[], int);
void mySelectionSort(int[], int);
void myBubbleSort(int[], int);
void myInsertionSort(int[], int);


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
