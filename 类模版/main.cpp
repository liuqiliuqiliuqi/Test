#include<iostream>
using namespace std;

template<typename T>
class Carry
{
public:


	Carry(int resize = 2)
	{
	//	cout << "Carry(int resize=0)" << endl;
		arr = new T[resize];
		_len = resize;
		_num = 0;
	}


	~Carry()
	{
	//	cout << "~Carry()" << endl;

		delete[]arr;
		_len = 0;
		_num = 0;
	}

	template <typename U>
	Carry<T>(const Carry<U> &src)
	{
	//	cout << "Carry(const Carry &src)" << endl;
		T* tmp= new T[src._len];
		int i = 0;
		for (; i < src._num; i++)
		{
			tmp[i] = src.arr[i];
		}
		arr = tmp;
		_len = src._len;
		_num = src._num;

	}


	Carry &operator = (const Carry& src)
	{
		if (this == &src)
		{
			return *this;
		}

		if (arr!=NULL)
		delete[]arr;

		int i = 0;
		for (; i < src._num; i++)
		{
			tmp[i] = src.arr[i];
		}
		arr = tmp;
		_len = src._len;
		_num = src._num;

		return *this;
	}



	void pushBack(T val)
	{
		//cout << "void pushBack(T val)" << endl;
		if (isFull())
		{
			resize();
		}
		arr[_num++] = val;
	}


	bool isFull()
	{
		//cout << "bool isFull()" << endl;

		if (_num == _len)
		{
			return 1;
		}
		return 0;
	}


	bool isEmpty()
	{
		//cout << "bool isEmpty()" << endl;
		if (_num == 0)
		{
			return 1;
		}
		return 0;
	}

	void resize()
	{
		//cout << "void resize()" << endl;

		T *brr = new T[_len + (_len >> 1)];
		int i = 0;
		for (; i < _num; i++)
		{
			brr[i] = arr[i];
		}
		delete[]arr;
		arr = brr;
		_len = _len + (_len >> 1);

	}

	void insert(int sit, T val)
	{
		//cout << "void insert(int sit, T val)" << endl;
		if (sit-1>_num || sit < 0)
		{
			cout << "sit error" << endl;
			return;
		}
		if (isFull())
		{
			resize();
		}
		for (int i = sit - 1; i <= _len; i++)
		{
			T tmp = _arr[i];
			_arr[i] = val;
			val = tmp;
		}
		_num++;
	}

	bool popBack()
	{
		//cout << "bool popBack()" << endl;
		if (isEmpty())
		{
			cout << "delete error" << endl;
			return 0;
		}
		_num--;
		return 1;
	}


	bool deleteSit(int sit)
	{
		//cout << "bool deleteSit(int sit)" << endl;
		if (sit > _num || sit < 0)
		{
			cout << "sit error!" << endl;
			return 0;
		}
		if (isEmpty())
		{
			cout << "delete error" << endl;
			return 0;
		}
		for (int i = sit-1; i < _num; i++)
		{
			arr[i] = arr[i + 1];
		}
		_num--;
	}


	T getBack()
	{
		//cout << "T getBack()" << endl;
		if (isEmpty())
		{
			cout << "getback error" << endl;
			return 0;
		}
		return arr[_num - 1];
	}


	void show()
	{
		for (int i = 0; i < _num; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	template<typename U>
	int find(U val)
	{
		if (isEmpty())
		{
			cout << "find error" << endl;
			return -1;
		}
		for (int i = 0; i < _num; i++)
		{

			if (arr[i] == val)
			{
				return i + 1;
			}
		}
		return 0;
	}

	template<>
	int find<char *>(char *val)
	{
		if (isEmpty())
		{
			cout << "find error" << endl;
			return -1;
		}
		for (int i = 0; i < _num; i++)
		{
			if (strcmp(val, arr[i]) == 0)
			{
				return i + 1;
			}
		}
		return 0;
	}

private:
	T *arr;
	int _len;
	int _num;
};

template<typename T, typename U = Carry<T>>
class Stack
{
public:
	Stack(){}
	~Stack(){}
	bool IsFull(U& carry)
	{
		carry.isFull();
	}
	bool IsEmpty(U& carry)
	{
		carry.isEmpty();
	}
	void Expand(U& carry)
	{
		carry.resize();
	}
	void Push(U& carry, T val)
	{
		carry.pushBack(val);
	}
	bool Pop(U& carry)
	{
		return carry.popBack();
	}
	T GetTop(U& carry)
	{
		return carry.getBack();
	}
	void show(U& carry)
	{
		carry.show();
	}
};


int main()
{
	Stack<int> stack;
	Carry<int> carry;
	for (int i = 0; i < 10; i++)
	{
		stack.Push(carry, i);
	}
	stack.show(carry);
	stack.Pop(carry);
	stack.show(carry);
	cout << stack.GetTop(carry) << endl;
	return 0;
}