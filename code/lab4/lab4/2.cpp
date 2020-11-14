#include<iostream>
using namespace std;
int main()
{
	int a;
	for (int i = 1; i <= 10000; i++)
	{
		a = 0;
		for (int j = 1; j < i; j++)
		{
			if (i%j == 0)
			{
				a += j;
			}
		}
		if (i == a)
		{
			cout << i << " " ;
		}
	}
	system("pause");
	return 0;
}