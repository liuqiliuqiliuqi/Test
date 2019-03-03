#ifndef MITERATOR_H
#define MITERATOR_H
#include<iostream>

using namespace std;

template<typename T>
class Mvector;


template<typename T>
class Miterator
{
private:
	Mvector<T>* _vec;
	int _pos;

public:
	Miterator(Mvector<T>* src, int pos)
	{
		_vec = src;
		_pos = pos;
	}

	Miterator(const Miterator& src)
	{
		_vec = src._vec;
		_pos = src._pos;
	}

	Miterator& operator=(const Miterator& src)
	{
		_vec = src._vec;
		_pos = src._pos;

		return *this;
	}

	bool operator==(const Miterator& src)
	{
		return (_vec == src._vec && _pos == src._pos)
	}

	bool operator!=(const Miterator& src)
	{
		return (_vec != src._vec || _pos != src._pos);
	}

	Miterator& operator++()
	{
		++_pos;
		return *this;
	}

	Miterator operator++(int)
	{
		return Miterator(_vec, _pos++);
	}

	Miterator& operator--()
	{
		--pos;
		return *this;
	}

	Miterator operator--(int)
	{
		return Miterator(_vec, _pos--);
	}

	T& operator*();

	T* operator->();//it.operator->()->

	friend class Mvector<T>;
};

#endif