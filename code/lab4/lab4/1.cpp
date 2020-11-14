#include<iostream>
using namespace std;
int main()
{
	long long int a,sum=0;
	cin >> a;
	while (a != 0)
	{
		sum += (a % 10);
		a = a / 10;
		if (a == 0 && sum > 9)
		{
			cout << sum << " ";
			a = sum;
			sum = 0;
		}
	}
	cout << sum << endl ;
	system("pause");
	return 0;
}