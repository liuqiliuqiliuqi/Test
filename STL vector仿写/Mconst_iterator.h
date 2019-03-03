#ifndef MCONST_MITERATOR_H
#define MCONST_MITERATOR_H
#include<iostream>

using namespace std;

template<typename T>
class Mvector;


template<typename T>
class Mconst_iterator
{
private:
	const Mvector<T>* _vec;
	int _pos;

public:
	Mconst_iterator(const Mvector<T>* src, int pos)
	{
		_vec = src;
		_pos = pos;
	}

	Mconst_iterator(const Mconst_iterator& src)
	{
		_vec = src._vec;
		_pos = src._pos;
	}

	Mconst_iterator& operator=(const Mconst_iterator& src)
	{
		_vec = src._vec;
		_pos = src._pos;

		return *this;
	}

	bool operator==(const Mconst_iterator& src)
	{
		return (_vec == src._vec && _pos == src._pos)
	}

	bool operator!=(const Mconst_iterator& src)
	{
		return (_vec != src._vec || _pos != src._pos);
	}

	Mconst_iterator& operator++()
	{
		++_pos;
		return *this;
	}

	Mconst_iterator operator++(int)
	{
		return Mconst_iterator(_vec, _pos++);
	}

	Mconst_iterator& operator--()
	{
		--pos;
		return *this;
	}

	Mconst_iterator operator--(int)
	{
		return Mconst_iterator(_vec, _pos--);
	}

	const T& operator*();

	const T* operator->();//it.operator->()->

	friend class Mvector<T>;
};

#endif