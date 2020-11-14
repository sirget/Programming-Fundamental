#include<stdio.h>
#include<iostream>
//using namespace std;
int main()
{
	int a,i=0;
	scanf_s("%d", &a);
	while (i<a)
	{
		int j = 0;
		while (j<a)
			{
				if ((i + j) % 2 == 0)
					printf("*");
				else
					printf("_");

				j++;
			}
		printf("\n");
		i++;
	}
	system("pause");

}