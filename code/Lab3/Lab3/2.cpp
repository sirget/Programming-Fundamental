#include <stdio.h>
#include <iostream>
int main()
{
	int x1, x2;
	scanf_s("%d %d", &x1, &x2);
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
	if(x2==1)
		printf("%d", x2);
	system("pause");
	return 0;
}