#include "../shared/Queue.h"

#include <iostream>

using namespace std;

int main()
{
	int n = 7, k = 3; // set n and k to the desired values

	Queue<int> q(n + 1);
	q.SetDebugFlag(false);

	// 처음에 n명 추가 (1, 2, ..., n)
	for (int i = 1; i <= n; i++)
		q.Enqueue(i);
	q.Print();

	{
		while (q.Size() != 1)
		{
			for (int i = 0; i < k - 1; ++i)
			{
				int first = q.Front();
				q.Dequeue();
				q.Enqueue(first);
			}

			int first = q.Front();
			q.Dequeue();
			cout << "Executed " << first << endl;
		}
	}
	
	cout << "Survivor: " << q.Front() << endl;

	return 0;
}