#include<iostream>
using namespace std;
int main()
{
	char x[30];
	char *p;
	p = x;
	cin >> x;
	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
		{
			printf("%c", *p - 'a' + 'A');
		}
		if (*p >= 'A' && *p <= 'Z')
		{
			printf("%c", *p - 'A' + 'a');
		}
		p++;
	}
	system("pause");
}