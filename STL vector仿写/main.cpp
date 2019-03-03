#include"Mvector.h"
#include<iterator>
#include<vector>
using namespace std;



template<typename Contain>//vector<int>
void show_iterator(Contain c)
{
	Contain::iterator it = c.begin();
	//*it = 22;
	for (it; it != c.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template<typename Contain>
void show_const_iterator(Contain c)
{
	Contain::const_iterator it = c.begin();//vector<int>::iterator
	//*it = 33;
	for (it; it != c.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
}


template<typename Contain>
void show_reverse_iterator(Contain c)
{
	Contain::reverse_iterator it = c.rbegin();
	for (it; it != c.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	show_iterator(v);

	show_const_iterator(v);

	show_reverse_iterator(v);























	Mvector<int> v1;
	v1.reserve(/* const Mvector<int>* const this*/5);

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	v1.show();

	cout << v1.back() << endl;
	cout << v1.front() << endl;

	v1.pop_back();
	v1.show();





	Mvector<int>::iterator it = v1.begin();
	for (it; it != v1.end(); it++)
	{
		cout << *it << "       ";
	}
	cout << endl;

	it = v1.begin();
	it++;

	v1.erase(it);

	it = v1.begin();
	for (it; it != v1.end(); it++)
	{
		cout << *it << "       ";
	}
	cout << endl;

	it = v1.begin();
	it++;

	v1.insert(it, 33);

	it = v1.begin();
	for (it; it != v1.end(); it++)
	{
		cout << *it << "       ";
	}
	cout << endl;

	cout << "====================" << endl;

	const Mvector<int> v2(v1);
	Mvector<int>::const_iterator it3 = v2.begin();
	//*it3 = 44;
	for (it3; it3 != v2.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << endl;









	return 0;
} 