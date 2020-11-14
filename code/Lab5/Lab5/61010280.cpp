#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
void gotoxy(int, int);
void print_ship(int,int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void setarealr(int);
void setareatd(int);
void bg(void);
int main()
{	
	setcursor(0);
	setcolor(2, 4);
	bg();
	setarealr(0);
	setarealr(80);
	setareatd(0);
	setareatd(28);
	int x=38, y=20;
	char ch = ' ';
	print_ship(x,y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x > 1)   { print_ship(--x, y); }
			if (ch == 'd' && x < 73)  { print_ship(++x, y); }
			if (ch == 'w' && y > 1)   {	erase_ship(x, y);
										print_ship(x, --y); }
			if (ch == 's' && y < 27 ) {	erase_ship(x, y);
										print_ship(x, ++y); }
			fflush(stdin);
		}
		Sleep(20);
	} while (ch != 'x');
	system("pause");
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void print_ship(int x,int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << " <-0-> " ;
}
void erase_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << "      ";
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void setarealr(int x)
{
	for (int j = 0; j < 29; j++)
	{
		gotoxy(x, j);
		cout << "|" ;
	}
}
void setareatd(int x)
{
	for (int i = 0; i < 81; i++)
	{
		gotoxy(i, x);
		cout << "-";
	}
}
void bg(void)
{
	for (int k = 0; k < 29; k++)
	{
		for (int l = 0; l < 80; l++)
		{
			cout << " ";
		}
		cout << endl;
	}
}
