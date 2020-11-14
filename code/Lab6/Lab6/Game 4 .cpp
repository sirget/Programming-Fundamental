#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
void gotoxy(int, int);
void print_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void setarealr(int);
void setareatd(int);
void bullet(int, int);
void erase_bullet(int, int);
int main()
{
	setcursor(0);
	setarealr(0);
	setarealr(80);
	setareatd(0);
	setareatd(28);
	int x = 38, y = 27, vec = 0, i = 0, statusbullet[5], bulletx[5], bullety[5];
	int *pstatusb, *pbullx, *pbully;
	pstatusb = statusbullet;
	pbullx = bulletx;
	pbully = bullety;
	char ch = ' ';
	print_ship(x, y);
	do {

		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x > 1)
			{
				vec = 1;
				setcursor(0);
			}
			if (ch == 'd' && x < 73)
			{
				vec = -1;
				setcursor(0);
			}
			if (ch == 's')
			{
				vec = 0;
				setcursor(0);
			}
			if (ch == ' ' && i < 5)
			{
				setcursor(0);
				*pbullx = x;
				*pbully = y - 1;
				*pstatusb = 1;
				if (pstatusb == &statusbullet[4])
				{
					pstatusb = statusbullet;
					pbullx = bulletx;
					pbully = bullety;
				}
				else
				{
					pstatusb++;
					pbullx++;
					pbully++;
				}
				i++;
			}
			fflush(stdin);
		}
		if (vec != 0)
		{
			if (vec == 1 && x > 1)
			{
				print_ship(--x, y);
			}
			if (vec == -1 && x < 73)
			{
				print_ship(++x, y);
			}
		}
		for (int k = 0; k < 5; k++)
		{
			if (statusbullet[k] == 1)
			{
				erase_bullet(bulletx[k], bullety[k]);
				if (bullety[k] > 1)
					bullet(bulletx[k], --bullety[k]);
				else
				{
					statusbullet[k] = 0;
					i--;
				}
			}
		}
		Sleep(50);
	} while (ch != 'x');
	system("pause");
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void print_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(7, 0);
	cout << " ";
	setcolor(2, 4);
	cout << "<-0->";
	setcolor(7, 0);
	cout << " ";
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
		cout << "|";
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
void erase_bullet(int x, int y)
{
	gotoxy(x + 3, y);
	cout << " ";
}
void bullet(int x, int y)
{
	gotoxy(x + 3, y);
	cout << "|";
}
