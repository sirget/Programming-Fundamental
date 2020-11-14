#include<iostream>
using namespace std;
int main()
{
	char str[100], a, *pstr = str;
	int n = 0;
	cin >> str;
	while (*pstr != '\0')
	{
		if (*pstr >= '0' && *pstr <= '9')
		{
			n = n * 10 + (int)*pstr - 48;
		}
		else
		{
			for (int i = 0; i < n; i++)
				cout << *pstr;
			n = 0;
		}
		pstr++;
	}
	system("pause");
}