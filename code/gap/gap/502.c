#include<stdio.h>
int main()
{
	int y, sum = 0;
	printf(" *** Multiplication Table *** \n");
	printf("Enter a number (2-100) : ");
	scanf("%d", &y);
	if (y <= 100 && y >= 2)
	{
		for (int i = 1; i <= 12; i++)
		{
			if (i >= 10)
				printf("   %d X %d = %d\n", y, i, y*i);
			else
				printf("   %d X %d  = %d\n", y, i, y*i);
		}
	}
	return 0;
}