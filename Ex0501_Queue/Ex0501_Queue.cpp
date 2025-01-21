#include "../shared/Queue.h"

#include <iostream>

#include <cassert>

int main()
{
	// FIFO(First In First Out)
	int size = 0;

	Queue<char> q(2); // capacity_ = 2에서 시작 (메모리 증가 확인)

	q.SetDebugFlag(true);

	q.Print();

	q.Enqueue('A');
	size = q.Size();
	assert(size == 1);
	q.Print();

	q.Enqueue('B');
	assert(q.Size() == 2);
	q.Print();

	q.Enqueue('C');
	assert(q.Size() == 3);
	q.Print();

	q.Enqueue('D');
	assert(q.Size() == 4);
	q.Print();

	q.Dequeue();
	assert(q.Size() == 3);
	q.Print();

	q.Dequeue();
	assert(q.Size() == 2);
	q.Print();

	q.Dequeue();
	assert(q.Size() == 1);
	q.Print();

	for (char c = 'E'; c <= 'K'; c++)
	{
		q.Enqueue(c);
		q.Print();
	}

	return 0;
}
