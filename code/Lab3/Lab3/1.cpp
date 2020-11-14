#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n, i, fact, j;
	printf("Enter the Number");
	scanf_s("%d", &n);
	printf("Prime Numbers are: \n");
	for (i = 1; i <= n; i++)
	{
		fact = 0;
		for (j = 2; j <= n; j++)
		{
			if (i%j == 0)
				fact++;
		}
		if (fact == 1)
			printf("%d ", i);
	}
	system("pause");
	return 0;
}