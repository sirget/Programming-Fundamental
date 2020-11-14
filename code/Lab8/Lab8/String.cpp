#include<iostream>
#include<cstring>
#include <stdio.h>
using namespace std;
int main()
{
	char str[100],a,*pstr = str;
	int n = 0;
	gets_s(str);
	while (*pstr != '\0')
	{
		if (*pstr >= '0' && *pstr <= '9')
		{
			n = n*10 + (int) *pstr - 48;
		}
		else
		{
			if (*(pstr - 1) < '0'||*(pstr - 1) > '9')
				cout << *pstr;
			else
			{
				for (int i = 0; i < n; i++)
					cout << *pstr;
				n = 0;
			}
		}
		pstr++;
	}
	system("pause");
}