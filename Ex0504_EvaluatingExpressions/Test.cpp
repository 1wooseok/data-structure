#include "../shared/Queue.h"
#include "../shared/Stack.h"

int getProiorty(const char ch)
{
	if (ch == '*' || ch == '/')
	{
		return 2;
	}

	if (ch == '+' || ch == '-')
	{
		return 1;
	}

	return 0;
}

void toPostfix(const Queue<char> infix)
{
	Stack<char> s;
	Queue<char> postfix;

	while (!infix.IsEmpty())
	{
		char ch = infix.Front();
		infix.Dequeue();

		if ('0' < ch && ch <= '9')
		{

		}
	}
}