#include<iostream>
#include<string>
using namespace std;

#if 0
class Compex
{
public:
	Compex(int real, int image)
		:_real(real), _image(image)
	{

	} 

	Compex(const Compex &src)
		:_real(src._real), _image(src._image)
	{

	}

	Compex operator =(const Compex &src)
	{
		_real = src._real;
		_image = src._image;
	}

	~Compex(){}

	Compex operator +(const Compex &src)
	{
		return Compex(_real + src._real, _image + src._image);
	}

	Compex operator+(int n)
	{
		return Compex(_real + n, _image);
	}

	Compex operator -(const Compex &src)
	{
		return Compex(_real - src._real, _image - src._image);
	}

	Compex operator-(int n)
	{
		return Compex(_real - n, _image);
	}

	ostream&  operator << (ostream & out)
	{
		out << "_real   " << _real;
		out << "_image  " << _image;
		out << endl;
		return out;
	}

	istream& operator>>(istream & in)
	{
		in >>_real;
		in >>_image;
		return in;
	}

	Compex operator ++()
	{
		return Compex(++_real, _image);
	}

	Compex operator ++(int)
	{
		return Compex(_real++, _image);//  ∫Û÷√++£ª
	}

	Compex operator--()
	{
		return Compex(--_real, _image);
	}

	Compex operator--(int)
	{
		return Compex(_real--, _image);
	}
private:
	int _real;
	int _image;
	friend Compex operator+(int n, Compex& src);
	friend Compex operator-(int n, Compex& src);
	friend ostream& operator<<(ostream &out, const Compex &src);
	friend istream&  operator >>(istream & in,  Compex &src);

	
}; 


ostream& operator <<(ostream & out, const Compex &src)
{
	out << "_real   " << src._real;
	out << "_image  " << src._image;
	out << endl;
	return out;
}


istream& operator >>(istream & in, Compex &src)
{
	in >> src._real;
	in >> src._image;
	return in;
}

Compex operator+(int n, Compex& src)
{
	return Compex(src._real + n, src._image);
}

Compex operator-(int n, Compex& src)
{
	return Compex(src._real - n, src._image);
}

#endif



class Mstring
{
public:

	Mstring(){}
	Mstring(const char *src)
	{
		if (NULL == src)
		{
			_str = NULL;
			return;
		}
		_str = new char[strlen(src) + 1];
		strcpy_s(_str, strlen(src) + 1, src);
		_size = strlen(src);
	}

	Mstring(const Mstring &str1, const Mstring &str2)
	{
		//if ()
		_str = new char[strlen(str1._str) + strlen(str2._str) + 1];

		memcpy_s(_str, strlen(str1._str) + 1, str1._str, strlen(str1._str) + 1);

		strcat_s(_str, strlen(str2._str) + strlen(str1._str)+1, str2._str);

		_size = str1._size + str2._size;
	}

	Mstring(const Mstring & src)
	{
		if (NULL == src._str)
		{
			_str = NULL;
			return;
		}
		_str = new char[src._size + 1];
		strcpy_s(_str, src._size + 1, src._str);
		_size = src._size;	
	}

	~Mstring()
	{
		if (NULL == _str)
		{
			return;
		}
		delete[]_str;
		_str = NULL;
		_size = 0;
	}

	Mstring operator+(const Mstring & src)
	{
		if (NULL == _str)
		{
			return src._str;
		}
		if (NULL == src._str)
		{
			return _str;
		}


		return Mstring(*this,src);
	}

	Mstring& operator+(const char* src)
	{
		strcat_s(_str, strlen(src) + _size + 1, src);
		_size += strlen(src);

		return *this;
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

		_str = new char[src._size + 1];
		strcpy_s(_str, src._size + 1, src._str);
		_size = src._size;

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

		_str = new char[strlen(src) + 1];
		strcpy_s(_str, strlen(src) + 1, src);
		_size = strlen(src);

		return *this;
	}
	

	bool operator>(const Mstring & src)const
	{
		if (strcmp(_str, src._str) > 0)
		{
			return true;
		}
		return false;

	}

	bool operator>(const char* src)const
	{
		if (strcmp(_str, src) > 0)
		{
			return true;
		}
		return false;
	}

	bool operator<(const Mstring & src)const
	{
		if (strcmp(_str, src._str) < 0)
		{
			return true;
		}
		return false;
	}

	bool operator<(const char* src)const
	{
		if (strcmp(_str, src) < 0)
		{
			return true;
		}
		return false;
	}


	bool operator==(const Mstring & src)const
	{
		if (strcmp(_str, src._str) == 0)
		{
			return true;
		}
		return false;
	}

	bool operator==(const char* src)const
	{
		if (strcmp(_str, src) == 0)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Mstring & src)const
	{
		if (strcmp(_str, src._str) != 0)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const char* src)const
	{
		if (strcmp(_str, src) != 0)
		{
			return true;
		}
		return false;
	}

	char &operator[](int pos)
	{
		return _str[pos];
	}

	char& operator*()
	{
		return *_str;
	}


	ostream& operator<<(ostream &out)
	{
		out << _str << "   ";
		out << _size;

		return out;
	}

	istream& operator>>(istream &in)
	{
		in >> _str;
		_size = strlen(_str);

		return in;
	}
private:

	char* _str;
	int _size;

	friend ostream& operator<<(ostream &out, Mstring& src);
	friend istream& operator>>(istream &in, Mstring& src);
	friend bool operator==(const char *str, const Mstring &src);



};





ostream& operator<<(ostream &out, Mstring& src)
{
	out << src._str << "   ";
	out << src._size;

	return out;
}

istream& operator>>(istream &in, Mstring& src)
{
	in >> src._str;
	src._size = strlen(src._str);

	return in;
}





int main()
{

	Mstring s1;
	
	s1 = "qdadasdd";
	s1.operator<<(cout);
	cout << endl;

	Mstring s2("qwedqd");
	s2.operator<<(cout);

	cout << endl;

	Mstring s3 = s1 + s2;
   s3.operator<<(cout);

	
	
	

	/*Compex c1(5, 5);
	Compex c2(3, 3);

	Compex c3 = c1 - c2;
	c3++;
	++c3;
	c3.operator<<(cout);*/

}