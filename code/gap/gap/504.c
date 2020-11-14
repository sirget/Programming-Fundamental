#include<stdio.h>
int main()
{
	int x, y, sum = 0;
	printf("Enter 2 whole numbers : ");
	scanf("%d %d", &x, &y);
	printf("Summation = ");
	if (x > y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	for (int i = x; i <= y; i++)
	{
		if (i == y)
			printf("%d", i);
		else
			printf("%d + ", i);
		sum += i;
	}
	printf(" = %d", sum);
	return 0;
}