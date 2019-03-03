
#include"Mstring.h"

int main()
{
	/*string str = "hello";
	string::iterator it = str.begin();
	for (it; it != str.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>::iterator it1 = vec.begin();
	for (it1; it1 != vec.end(); it1++)
	{
		cout << *it1 << " ";
	}*/

	Mstring str = "hello";
	Mstring::iterator it = str.begin();
	for (it; it != str.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
    
}