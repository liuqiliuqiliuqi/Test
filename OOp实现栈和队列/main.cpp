#include<iostream>
#include<assert.h>
using namespace std;

#define SIZE 10


class Stack
{
private:
	int *_data;
	int _size;
	int _top;
public:

	
	Stack()
	{
		_data = new int[SIZE];
		_size = SIZE;
		_top = 0;
	}

	void Expand(Stack &stack)
	{
		assert(&stack != NULL);
		int *s = new int[SIZE*2];
		for (int i = 0; i < stack._top; ++i)
		{
			s[i] = stack._data[i];
		}
		delete stack._data;
		stack._data = s;
		stack._size *= 2;
	}

	bool IsFull(Stack &stack)
	{
		assert(&stack != NULL);

		if (stack._top == stack._size)
		{
			return true;
		}

		return false;
	}

	bool  IsEmpty(Stack &stack)
	{
		assert(&stack != NULL);

		if (stack._top == 0)
		{
			return true;
		}

		return false;
	}

	int Push(Stack &stack,int val)
	{
		assert(&stack != NULL);

		if (IsFull(stack))
		{
			Expand(stack);
			if (IsFull(stack))
			{
				return false;
			}
		}

		stack._data[stack._top++] = val;

		return true;
	}

	int Pop(Stack &stack)
	{
		assert(&stack != NULL);

		if (IsEmpty(stack))
		{
			return false;
		}
		int val = stack._data[stack._top--];
		return  val;
	}

	void Show(Stack &stack)
	{
		for (int i = 0; i < stack._top; ++i)
		{
			cout << stack._data[i] << endl;
		}
	}

	Stack(const Stack & src)
	{
		_data = new int[src._size];
		for (int i = 0; i < src._top; ++i)
		{
			_data [i]= src._data[i];
		}
		_top = src._top;
		_size = src._size;
	}

	Stack &operator=(const Stack & src)
	{
		if (this == &src)
		{
			return *this;
		}
		if (NULL != _data)
		{
			delete[]_data;
		}
		_data = new int[src._size];
		for (int i = 0; i < src._top; ++i)
		{
			_data[i] = src._data[i];
		}
		_top = src._top;
		_size = src._size;
	}

	~Stack()
	{
		delete[]_data;
		_data = NULL;
		_size = 0;
		_top = 0;
	}

	
};

class Queue
{
private:
	int *_data;
	int _head;
	int _tail;
public:
	Queue()
	{
		_data = new int[SIZE];
		_head = _tail = 0;
	}

	int IsFull(Queue& que)
	{
		assert(&que != NULL);

		if ((que._tail + 1) % SIZE == que._head)
		{
			return true;
		}

		return false;
	}

	int IsEmpty(Queue& que)
	{
		assert(&que != NULL);

		if (que._head == que._tail)
		{
			return true;
		}

		return false;
	}

	int PushQue(Queue &que, int val)
	{
		assert(&que != NULL);

		if (IsFull(que))
		{
			return false;
		}

		que._data[que._tail++] = val;
		que._tail %= SIZE;

		return true;
	}

	int PopQue(Queue &que)
	{
		assert(&que != NULL && que._data != NULL);

		if (IsEmpty(que))
		{
			return false;
		}

		int val = que._data[que._head++];
		que._head %= SIZE;

		return val;
	}

	Queue(const Queue & src)
	{
		_data = new int[SIZE];
		for (int i = src._head; i < src._tail; ++i)
		{
			_data[src._head] = src._data[i];
		}
		_head = src._head;
		_tail = src._tail;
	}

	Queue operator=(const Queue &src)
	{
		if (this == &src)
		{
			return *this;
		}
		if (_data != NULL)
		{
			delete[]_data;
		}
		_data = new int[SIZE];
		for (int i = src._head; i < src._tail; ++i)
		{
			_data[src._head] = src._data[i];
		}
		_head = src._head;
		_tail = src._tail;

		return *this;
	}

	~Queue()
	{
		if (NULL != _data)
		{
			delete[]_data;
			_data = NULL;
			_head = 0;
			_tail = 0;

		}
	}

	void Show(Queue &que)
	{
		assert(this != NULL);
		for (int i = que._head; i < que._tail; i++)
		{
			cout << que._data[i] << endl;
		}

	}
};

int main()
{
	/*Stack stack;
	
	for (int i = 0; i < SIZE; i++)
	{
		stack.Push(stack, i);
	}
	stack.Pop(stack);
	stack.Show(stack);*/

	Queue que;
	for (int i = 0; i < SIZE; i++)
	{
		que.PushQue(que, i);
	}
	que.PopQue(que);
	que.Show(que);
	return 0;
}



