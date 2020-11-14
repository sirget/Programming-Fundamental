#include<iostream>
using namespace std;
int main()
{
	bool ch = true;
	char x[30],y[30];
	char *p1, *p2;
	cin >> x;
	cin >> y;
	p1 = x;
	p2 = y;
	while (*p1 != '\0' && *p2 != '\0')
	{
		if (*p1 == *(p1 + 1))
		{
			p1++;
		}
		if (*p2 == *(p2 + 1))
		{
			p2++;
		}
		if (*p1 != *(p1 + 1) && *p2 != *(p2 + 1))
		{
			if (*p1 != *p2)
			{
				ch = false;
				break;
			}
			p1++;
			p2++;
		}
	}
	if (ch)
		cout << "Uniq";
	else
		cout << "Not Uniq";
	system("pause");
}