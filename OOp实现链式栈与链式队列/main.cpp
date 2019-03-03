#include<iostream>
#include<assert.h>
using namespace std;

typedef int ElemType;


class LinkStack
{
private:

	class Node
	{
	private:
		ElemType _data;
		Node *_next;

		friend class LinkStack;
	public:
		Node()
		{
			_next = NULL;
		}
		~Node()
		{

		}

		 

	};

	Node _top;
	int _count;



public:


	LinkStack()
		:_top()
	{
		_count = 0;
	}

	LinkStack(const LinkStack & src)
	{
		_top._next = src._top._next;
		for (int i = 0; i < _count; i++)
		{
			Push(src._top._data);
		}
	}

	LinkStack operator=(const LinkStack & src)
	{
		if (this == &src)
		{
			return *this;
		}

		if (NULL != _top._next)
		{
			delete _top._next;
		}
		_top._next = src._top._next;
		for (int i = 0; i < _count; i++)
		{
			Push(src._top._data);
		}

		return *this;

	}

	~LinkStack()
	{
		
	}

	Node * BuyNode(ElemType val, Node *next)
	{
		Node *s = new Node;
		assert(s != NULL);

		s->_data = val;
		s->_next = next;

		return s;
	}

	void Push(ElemType _data)
	{
		Node *s = LinkStack::BuyNode(_data, _top._next);
		s->_next = _top._next;
		_top._next = s;
		_count++;

	}

	void Pop()
	{
		Node *s = _top._next;
		_top._next = s->_next;
		delete s;
		_count--;
	}

	int getTop()
	{
		int  val = _top._next->_data;
		return val;
	}
	
	void Show()
	{
		Node *s = &_top;
		while(s->_next!= NULL)
		{
			s = s->_next;
			cout << s->_data <<" \t" ;
		}
	}


};

class LinkQueue
{

private:
	class Node
	{
	private:
		ElemType _data;
		Node *_next;

		friend class LinkQueue;
	public:
		Node()
		{
			_next = NULL;
		}
		~Node()
		{

		}
	};

	Node _head;

	int _count;

	friend void  Push(ElemType _data);


public:
	LinkQueue()
		:_head()
	{
		_count = 0;
	}

	LinkQueue(const LinkQueue & src)
	{
		_head._next = src._head._next;
		for (int i = 0; i < _count; i++)
		{
			Push(src._head._data);
		}
	}

	LinkQueue operator=(const LinkQueue & src)
	{
		if (this == &src)
		{
			return *this;
		}
		if (NULL != _head._next)
		{
			delete _head._next;
		}
		_head._next = src._head._next;
		for (int i = 0; i < _count; i++)
		{
			Push(src._head._data);
		}

		return *this;
	}

	~LinkQueue()
	{
		_count = 0;
	}

	Node * BuyNode(ElemType val, Node *next)
	{
		Node *s = new Node;
		assert(s != NULL);

		s->_data = val;
		s->_next = next;

		return s;
	}

	void Push(ElemType _data)
	{
		Node *s = LinkQueue::BuyNode(_data, _head._next);
		s->_next = _head._next;
		_head._next = s;
		_count++;
	}

	void Pop()
	{
		Node *s = _head._next;
		for (int i = 0; i < _count-2; i++)
		{
			s = s->_next;
		}
		Node *p = s->_next;
		s->_next = NULL;
		delete p;
		_count--;
	}

	int getPop()
	{
		Node *s = _head._next;
		while (s->_next != NULL)
		{
			s = s->_next;
		}
		int val = s->_data;
		return val;
	}

	void Show()
	{
		Node *s = &_head;
		while (s->_next != NULL)
		{
			s = s->_next;
			cout << s->_data << " \t";
		}
	}

};



int main()
{
	LinkStack a;
	//LinkQueue a;
	for (int i = 0; i < 5; i++)
	{
		a.Push(i);
	}
	a.Show();

	cout << " " << endl;
	a.Pop();
	a.Show();
      cout << " " << endl;
	cout << a.getTop() <<endl;
	//cout << a.getPop() << endl;



}