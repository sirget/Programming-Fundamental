#include<iostream>
using namespace std;
int IsPrime(int,int);
int main()
{
	int x, a;
	cin >> x;
	a = IsPrime(x,x/2);
	if (a == 1)
		cout << "Prime Number" << endl ;
	else
		cout << "Not Prime Number" << endl ;
	system("pause");
	return 0;
}
int IsPrime(int x,int i)
{
	if (i == 1)
		return 1;
	else
	{
		if (x%i == 0)
			return 0;
		else
			IsPrime(x, i - 1);
	}
}