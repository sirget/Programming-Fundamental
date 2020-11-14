#include<iostream>
using namespace std;
int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(max(a, b), max(c, d)) << endl;
	system("pause");
}