#include<iostream>
#include<string>
using namespace std;
int main()
{
	string x;
	getline(cin, x);
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] >= 'A' && x[i] <= 'Z')
		{
			cout << x[i];
		}
	}
	cout << endl;
	system("pause");
}