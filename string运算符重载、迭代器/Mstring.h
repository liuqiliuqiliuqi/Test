#ifndef STRING_H
#define STRING_H

#include<iostream>
using namespace std;



class Miterator;

class Mstring
{
public:
	typedef Miterator iterator;


	Mstring(const char *src = NULL)
	{
		if (NULL == src)
		{
			_str = NULL;
			return;
		}
		_str = new char[strlen(src) + 1+4];
		strcpy_s(getStart(), strlen(src) + 1, src);
		_size = strlen(src);
		getCount() =1;
	}



	Mstring(const Mstring & src)
	{
		if (NULL == src._str)
		{
			_str = NULL;
			return;
		}
		_str = src._str;
		_size = src._size;
		getCount() += 1;

	}

	~Mstring()
	{
		if (NULL == _str)
		{
			return;
		}
		if (_str != NULL && --getCount() == 0)
		{
			delete[]_str;
		}
		
		_str = NULL;
		_size = 0;
	}


	

	Mstring operator=(const Mstring & src)
	{
		if (this == &src)
		{
			return *this;
		}

		if (_str != NULL)
		{
			delete[]_str;
		}
		if (src._str == NULL)
		{
			return *this;
		}

		_str = src._str;
		_size = src._size;
		getCount() += 1;

		return *this;
	}

	Mstring& operator=(const char* src)
	{
		if (_str != NULL)
		{
			delete[]_str;
		}
		if (NULL == src)
		{
			_str = NULL;
			return *this;
		}

		_str = new char[strlen(src) + 1+4];
		strcpy_s(getStart(), strlen(src) + 1, src);
		_size = strlen(src);
		getCount() = 1;
		return *this;
	}

	


	char &operator[](int pos)
	{
		if (_str == NULL)
		{
			throw "error";
		}
		if (pos + 1 > _size || pos < 0)
		{
			throw "error";
		}
		if (getCount() != 1)
		{
			char *s = new char[strlen(getStart()) + 5];
			strcpy_s(s+4, strlen(getStart()) + 1, getStart());
			--getCount();
			_str = s;
			getCount() = 1;
		
		}
		return _str[pos+4];
	}

	


	ostream& operator<<(ostream &out)
	{
		out << getStart() << "   ";
		out << getCount() << "   ";
		out << _size<<"   ";
		return out;
	}

	istream& operator>>(istream &in)
	{
		in >> getStart();
		_size = strlen(_str) - 4;

		return in;
	}

	iterator begin();
	iterator end();
private:

	char* _str;
	int _size;

	int& getCount()
	{
		return *((int *)_str);
	}

	 char* getStart()const
	{
		return  _str + 4;
	}

	friend ostream& operator<<(ostream &out, Mstring& src);
	friend istream& operator>>(istream &in, Mstring& src);


};




class Miterator
{
public:

	Miterator(Mstring&str, int pos)
		:_str(str), _pos(pos)
	{

	}

	Miterator(const Miterator& src)
		:_str(src._str), _pos(src._pos)
	{

	}

	char &operator*()
	{
		return _str[_pos];
	}

	bool operator!=(const Miterator &src)
	{
		return (&_str != &src._str) || (src._pos != _pos);
	}

	Miterator operator++(int)
	{
		return Miterator(_str, _pos++);
	}


private:
	Mstring &_str;
	int _pos;
};

#endif
//string¿‡
#if 0

int main()
{

	Mstring s1("2414234");
	s1.operator<<(cout);
	cout << endl;
	Mstring s2 = s1;
	s2.operator<<(cout);
	//cout << endl;
	//Mstring s3 = "1231";
	//s3.operator<<(cout);


	//cout << endl;
	//Mstring s4("redr");
	//cin >> s4;
	//cout << s4;
	cout << endl;
	Mstring s3 = s1;
	s3.operator<<(cout);
	/*Mstring s3 = "dsad";
	s3[2] = 'f';
	s3.operator<<(cout);*/

	s2[2] = 'a';
	s2.operator<<(cout);
	cout << endl;
	s3.operator<<(cout);

	//Mstring s3;
	//s3 = "dsfdsdaf";
	//cout << s3 << endl;

}

#endif


