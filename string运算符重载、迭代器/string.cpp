#include"Mstring.h"

Mstring::iterator Mstring::begin()
{
	return Miterator(*this, 0);
}

Mstring::iterator Mstring::end()
{
	return Miterator(*this, _size);
}

ostream& operator<<(ostream &out, Mstring& src)
{
	out << src._str + 4 << "   ";

	out << src.getCount() << "     ";
	out << src._size << "   ";

	return out;
}

istream& operator>>(istream &in, Mstring& src)
{

	in >> src.getStart();

	src._size = strlen(src.getStart());

	return in;
}