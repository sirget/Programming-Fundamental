#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a=5,i,j;
	int n = 2 * a - 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i>abs(j-a)&&i<=-abs(j-a)+n)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}