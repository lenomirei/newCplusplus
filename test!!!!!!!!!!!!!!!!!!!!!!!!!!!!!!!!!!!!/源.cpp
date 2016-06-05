#include<iostream>
using namespace std;


void QuickSort(int *a ,size_t length )
{
	if (length < 1)
	{
		return;
	}
	int value = a[0];
	int begin = 0;
	int end = length - 1;
	while (begin < end)
	{
		
		for (; begin < end; end--)
		{
			if (a[end] < value)
			{
				a[begin++] = a[end];
				break;
			}
		}
		for (; begin < end; begin++)
		{
			if (a[begin] > value)
			{
				a[end--] = a[begin];
				break;
			}
		}

	}
	a[begin] = value;
	QuickSort(a,begin);
	QuickSort(a + begin + 1,  length - begin - 1);
}



int main()
{
	int a[10] = { 6,7,8,9,0,1,2,3,4,5 };
	QuickSort(a, 10);
	return 0;
}