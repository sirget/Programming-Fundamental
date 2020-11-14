#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
int main()
{
	string str;
	char a;
	int n = 0;
	getline(cin, str);
	char *pstr = str;
	while (*pstr != '\0')
	{
		if (*pstr >= '0' && *pstr <= '9')
		{
			n += (int)*pstr - 48;
			//cout << n << " ";
			if (*(pstr + 1) >= '0'&&*(pstr + 1) <= '9')
			{
				n = n * 10;
			}
		}
		if ((*pstr >= 'a'&&*pstr <= 'z') || (*pstr >= 'A'&&*pstr <= 'Z'))
		{
			for (int i = 0; i < n; i++)
			{
				cout << *pstr;
			}
			n = 0;
		}
		pstr++;
	}
	system("pause");
}