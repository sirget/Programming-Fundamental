#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, y, x;
	cin >> a;
	for (y = 1; y <= 2*a-1; y++)
	{
		for (x = 1; x <= 2*a-1; x++)
		{
			if (y <= abs(x - a) + a && y >= -abs(x - a) + a)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}