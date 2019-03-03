#ifndef MVECTOR_H
#define MVECTOR_H

#include<iostream>
#include<vector>
#include"Miterator.h"
#include"Mconst_iterator.h"
using namespace std;

template<typename T>
class Mvector
{
private:
	T* _arr;
	int _valSize;
	int _len;

	void _reserve()
	{
		if (_len == 0 || _len == 1)
		{
			_len++;
		}

		_len = _len + (_len >> 1);

		T* p = new T[_len];

		for (int i = 0; i < _valSize; i++)
		{
			p[i] = _arr[i];
		}

		if (NULL != _arr)
		{
			delete[]_arr;
		}
		_arr = p;
	}

public:
	typedef  Miterator<T> iterator;
	typedef  Mconst_iterator<T> const_iterator;

	Mvector()
	{
		_arr = NULL;
		_valSize = 0;
		_len = 0;
	}

	Mvector(const Mvector& src)
	{
		if (0 == src._len)
		{
			_arr = NULL;
			_valSize = 0;
			_len = 0;

			return;
		}

		_arr = new T[src._valSize];
		for (int i = 0; i < src._valSize; i++)
		{
			_arr[i] = src._arr[i];
		}

		_valSize = src._valSize;
		_len = src._len;
	}

	~Mvector()
	{
		if (NULL != _arr)
		{
			delete[]_arr;
		}
	}

	Mvector& operator=(const Mvector& src)
	{
		if (this == &src)
		{
			return *this;
		}

		if (NULL != _arr)
		{
			delete[]_arr;
		}

		if (0 == src._len)
		{
			_arr = NULL;
			_valSize = 0;
			_len = 0;

			return;
		}

		_arr = new T[src._valSize];
		for (int i = 0; i < src._valSize; i++)
		{
			_arr[i] = src._arr[i];
		}

		return *this;
	}

	T& operator[](int pos)
	{
		return _arr[pos];
	}

	const T& operator[](int pos)const
	{
		return _arr[pos];
	}

	void push_back(const T& val)
	{
		if (full())
		{
			_reserve();
		}

		_arr[_valSize++] = val;
	}

	void pop_back()
	{
		if (!empty())
		{
			_valSize--;
		}
	}

	T front()
	{
		if (!empty())
		{
			return _arr[0];
		}
		throw "vector is empty";
	}

	T back()
	{
		if (!empty())
		{
			return _arr[_valSize - 1];
		}

		throw "vector is empty";
	}

	int size()
	{
		return _valSize;
	}

	void clear()
	{
		_valSize = 0;
	}

	void reserve(int len)
	{
		if (len < _len)
		{
			return;
		}

		T* p = new T[len];
		for (int i = 0; i < _valSize; i++)
		{
			p[i] = _arr[i];
		}

		if (NULL != _arr)
		{
			delete[]_arr;
		}

		_arr = p;
		_len = len;
	}

	bool empty()
	{
		return _valSize == 0;
	}

	bool full()
	{
		return _valSize == _len;
	}

	iterator insert(iterator it, const T& val)
	{
		if (full())
		{
			_reserve();
		}

		if (it._pos > _valSize || it._pos < 0)
		{
			throw "bad iterator";
		}

		for (int i = _valSize - 1; i >= it._pos; i--)
		{
			_arr[i + 1] = _arr[i];
		}

		_valSize++;
		_arr[it._pos] = val;

		return it;
	}

	iterator erase(iterator it)
	{
		if (empty())
		{
			throw "contrain is empty";
		}

		if (it._pos > _valSize || it._pos < 0)
		{
			throw "bad iterator";
		}

		for (int i = it._pos; i < _valSize; i++)
		{
			_arr[i] = _arr[i + 1];
		}

		_valSize--;

		return it;
	}

	iterator begin()
	{
		return iterator(this, 0);
	}

	iterator end()
	{
		return iterator(this, _valSize);
	}

	const_iterator begin()const
	{
		return const_iterator(this, 0);
	}

	const_iterator end()const
	{
		return const_iterator(this, _valSize);
	}

	void show()
	{
		for (int i = 0; i < _valSize; i++)
		{
			cout << _arr[i] << "  ";
		}
		cout << endl;
	}
};

template<typename T>
T& Miterator<T>::operator*()
{
	return (*_vec)[_pos];
}

template<typename T>
T* Miterator<T>::operator->()
{
	return (*_vec)[pos];
}




template<typename T>
const T& Mconst_iterator<T>::operator*()
{
	return (*_vec)[_pos];
}

template<typename T>
const T* Mconst_iterator<T>::operator->()
{
	return (*_vec)[pos];
}

#endif