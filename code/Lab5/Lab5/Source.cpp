#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
void print_ship(int, int);
int main()
{
	for (int i = 0; i < 74; i++)
	{
		print_ship(i, 20);
		Sleep(500);
	}
	system("pause");
	return 0;
}
void print_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << " <-0-> ";
}

