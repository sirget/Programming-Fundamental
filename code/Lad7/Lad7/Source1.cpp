#include<iostream>
using namespace std;
int a = 10, b = 20;
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	//cin >> a >> b;
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b;
	system("pause");
}