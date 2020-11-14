#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {

	int x;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (i <= -(abs(j)) && i >= (abs(j)))
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	system("pause");
}