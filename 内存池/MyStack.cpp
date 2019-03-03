#ifndef MYSTACK_H
#define MYSTACK_H
#define LEN 10
#include<iostream>
using namespace std;

template<typename T>
class MyStack
{
public:
	class Node;
	MyStack()
	{
		_head = NULL;
	}

	~MyStack()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
	bool isEmpty()
	{
		return _head == NULL;
	}
	void push(T val)
	{
		Node *p = new Node;
		p->_val = val;
		p->_next = NULL;
		if (isEmpty())
		{
			_head = p;
		}
		else
		{
			p->_next = _head;
			_head = p;
		}
	}

	void pop()
	{
		if (isEmpty()) throw "queue is empty";
		Node *q = _head;
		_head = _head->_next;
		delete q;
	}

	void show()
	{
		Node *p = _head;
		while (p != NULL)
		{

			cout << p->_val << " ";
			p = p->_next;
		}
		cout << endl;
	}

	T top()
	{
		return _head->_val;
	}

private:

	class space
	{
	public:
		static space* getSpace()
		{
			if (NULL == _space)
			{
			
				if (NULL == _space)
				{
					_space = new space();
				}
			
			}

			return _space;
		}

	private:
		space()
		{
			Node *tmp = new Node[LEN];

			int i = 0;
			for (; i < LEN - 1; i++)
			{
				tmp[i]._next = &tmp[i + 1];
			}
			tmp[i]._next = NULL;

			_pool = &tmp[0];
		}

		static space* _space;
		Node *_pool;


			friend class Node;
	};


	class Node
	{
	private:
		T _val;
		Node *_next;
		static space* _space;
		friend class MyStack;
	public:
		Node()
		{
			_next = NULL;
		}

		Node(T val)
		{
			_val = val;
			_next = NULL;
		}

		void *operator new(size_t size)
		{
			
			cout << "void *operator new(size_t size)" << endl;
			
			if (_space->_pool == NULL)
			{
				Node *tmp = new Node[LEN];

				int i = 0;
				for (; i < LEN - 1; i++)
				{
					tmp[i]._next = &tmp[i + 1];
				}
				tmp[i]._next = NULL;

				_space->_pool = &tmp[0];
			}
		

			Node* mem = _space->_pool;
			_space->_pool = _space->_pool->_next;

			return mem;
		}

		void operator delete(void *p)
		{
			cout << "void operator delete(void *p)" << endl;
			Node *tmp = (Node*)p;

			tmp->_next = _space->_pool;
			_space->_pool = tmp;
		}

		
	};
	Node* _head;

};

template<typename T>
typename MyStack<T>::space* MyStack<T>::Node::_space = MyStack<T>::space::getSpace();

template<typename T>
typename MyStack<T>::space* MyStack<T>::space::_space = NULL;





int main()
{
	MyStack<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	a.pop();
	a.show();
}

#endif