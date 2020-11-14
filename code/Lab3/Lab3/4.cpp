#include<stdio.h>
#include<iostream>
int main()
{
	int j, k;
	for ( j = 1 ; j <= 333 ; j++)
	{
		for (k = 1; k <= 666 ; k++)
		{
			if ((1000 - j - k)*(1000 - j - k) == j * j + k * k)
				printf("%d %d %d", 1000 - j - k, j, k);
		}
	}
	system("pause");
}