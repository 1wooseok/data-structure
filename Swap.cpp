#include <iostream>

using namespace std;

void swap(int& n1, int& n2)
{
    /*int temp = a;
    a = b;
    b = temp;*/

    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
}

void print()
{
    cout << boolalpha;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (!(j <= i))
            {
                cout << i << " " << j << " " << (i <= j) << endl;
            }
            else
            {
                cout << j << " " << i << " " << (j <= i) << endl;
            }
        }
    }

    cout << endl;
    cout << endl;

    int arr[2];

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            arr[0] = i;
            arr[1] = j;

            if (arr[0] > arr[1])
            {
                swap(arr[0], arr[1]);
            }

            cout << arr[0] << " " << arr[1] << " " << (arr[0] <= arr[1]) << endl;
        }
    }
}
