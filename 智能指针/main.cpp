#include<iostream>
#include<map>
using namespace std;

template<typename T>

class smartPtr
{
private:
	T *_ptr; 
	static map<T*, int> _num;//指针和引用计数


public:
	smartPtr(T*p)
	{
		_ptr = p;
		//先找
		if (_num.find(p) != _num.end())
		{
			_num[p]++;
		}
		else
		{
			_num.insert(make_pair(p, 1));
		}
		cout << _ptr << ":" << _num[_ptr] << endl;
		
	}
	~smartPtr()
	{
		cout << "~smartPtr()" << endl;
		if (--_num[_ptr] == 0)
		{
		delete _ptr;
		}
		cout << _ptr << ":" << _num[_ptr] << endl;
	}
	smartPtr(const smartPtr &src)
	{
		_ptr = src._ptr;
		_num[src._ptr]++;
	}

	T &operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{ 
		return _ptr;
	}
};

template<typename T>
map<T*, int>smartPtr<T>::_num = map<T*, int>();

int main()
{
	smartPtr<int> p = new int;
	//<int> p1 = new int;
	//smartPtr<int> p2 = new int;
	//smartPtr<int> p3 = new int;
	//smartPtr<int> p4 = new int;

	smartPtr<int> p1 = p;
	smartPtr<int> p2 = p;
	smartPtr<int> p3 = p;
	smartPtr<int> p4 = p;

	return 0;

}