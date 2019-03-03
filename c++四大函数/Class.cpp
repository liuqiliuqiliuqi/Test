#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

class CGoods
{
public:
	
	
	CGoods(const char *name =NULL,int num=0, double price=0)
	{
		if (_name != NULL)
		{
			_name = new char[strlen(name) + 1];
			strcpy_s(_name, strlen(name) + 1, name);
		}
		else
		{
			_name = NULL;         
		}
		_num = num;
		_price = price;
	}
	
	CGoods(const CGoods &src)
	{
		_name = new char[strlen(src._name) + 1];
		strcpy_s(_name, strlen(src._name) + 1, src._name);
		_num = src._num;
		_price = src._price;
	}

	CGoods &operator=(const CGoods & src)
	{
		//·ÀÖ¹×Ô¸³Öµ
		if (this == &src)
		{
			return *this;
		}
		//·ÀÖ¹ÄÚ´æÐ¹Â¶
		if (_name != NULL)
		{
			delete[]_name;
		}
		//·ÀÖ¹Ç³¿½±´
		_name = new char[strlen(src._name) + 1];
		strcpy_s(_name, strlen(src._name) + 1, src._name);
		_num = src._num;
		_price = src._price;

		return *this;

	}

	~CGoods()
	{
		delete[]_name;
		_name = NULL;
	}

	void show()
	{
		cout << _name << endl;
		cout << _num << endl;
		cout << _price << endl;
	}
private:
	char*_name;
	int _num;
	double _price;

	
};

int main()
{
	CGoods cgood1("»ðÍÈ", 20, 1.5);
	cgood1.show();


	CGoods cgood2(cgood1);
	cgood2.show();

	CGoods cgood3 = cgood1;
	cgood3.show();

	CGoods cgoods34 = "asd";
		
}

