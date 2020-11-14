#include <stdio.h>
#include <iostream>
int main()
{
	int i , j , x1, x2, maxi=0, max1, max2;
	for (i = 3; i < 200 ; i++)
	{
		for (j = i+1 ; j < 200 ; j++)
		{
			x1 = i;
			x2 = j;
			while (x1 != 0)
			{
				if (x2 > x1)
				{
					int x;
					x = x2;
					x2 = x1;
					x1 = x;
				}
				x1 = x1 % x2;
			}
			if (x2 > maxi)
			{
				maxi = x2;
				max1 = i;
				max2 = j;
			}
		}
	}
	printf("%d %d %d\n", max1, max2, maxi);
	system("pause");
	return 0;
}