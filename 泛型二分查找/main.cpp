#include<iostream>
#include<vector>
using namespace std;

template<typename T>
int Compare(T a, T b)
{
	if (a < b)
	{
		return -1;
	}
	if (a == b)
	{
		return 0;
	}

		return 1;

}

template<>
int Compare<char *>(char *a, char *b)
{
	if (strcmp(a, b) == 0)
	{
		return 0;
	}
	if (strcmp(a, b) < 0)
	{
		return -1;
	}

		return 1;

}


template<typename T,typename U,typename P>
int Binary_Search(T a,U val,int left, int right,P Compare)
{
	int pos = -1;
	int mid = (right - left + 1) / 2 + left;
	if (left <= right)
	{
		if (Compare(val, a[mid]) == -1)
		{
			pos = Binary_Search(a, val, left, mid - 1, Compare);
		}
		if (Compare(val, a[mid]) == 1)
		{
			pos = Binary_Search(a, val, mid + 1, right, Compare);
		}
		if (Compare(val, a[mid]) == 0)
		{
			return mid;
		}
	}
	return pos;

}

int main()
{
	int arr[11] = { 1, 2, 5, 6, 8, 10, 13, 15, 18, 34};
	int len = sizeof(arr) / sizeof(arr[0]);

	char *c[] = { "zxc","zzx","zzz" };
	char *v = "zz";
	int size = sizeof(c) / sizeof(c[0]);
	/*vector<int>Array(arr, arr + len);*/
	int a=Binary_Search(c, v, 0, size-1, Compare<char*>);
	printf("%d", a);
}