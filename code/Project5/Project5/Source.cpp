#include<iostream>
using namespace std;
void swap(char *str,int p1, int p2)
{
	char tmp = *(str + p1);
	*(str + p1) = *(str + p2);
	*(str + p2) = tmp;
}
int main()
{	
	char num[4] = { "123" },strx[20];
	cin >> strx;
	char *pstr = strx;
	while (*pstr != '\0')
	{
		if (*pstr == 'A')
		{
			swap(num, 0, 1);
		}
		if (*pstr == 'B')
		{
			swap(num, 1, 2);
		}
		if (*pstr == 'C')
		{
			swap(num, 0, 2);
		}
		pstr++;
	}
	cout << num;
	system("pause");
}