#include<stdio.h>
#include<iostream>
int main()
{
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == b * b + a * a))
		printf("Right Triangle");
	else
		printf("Not Right Triangle");
	system("pause");
	return 0;
}