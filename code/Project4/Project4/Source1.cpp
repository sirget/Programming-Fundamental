#include<iostream>
using namespace std;
int main()
{
	bool ch = true;
	char x[30];
	char *p1,*p2;
	int i = 0,j = 0;
	p1 = x;
	p2 = x;
	cin >> x;
	while (*p2!='\0')
	{
		p2++; i++;
	}
	p2--;
	i /= 2;
	while (j<=i)
	{
		if (*p1 != *p2)
		{
			ch = false;
			break;
		}
		p1++;
		p2--;
		j++;
	}
	if (ch)
		cout << "Palindrome";
	else
		cout << "Not Palindrome";
	system("pause");
}