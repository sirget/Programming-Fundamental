#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<cstring>
using namespace std;
struct status
{
	int sta = 0;
	int bulletx;
	int bullety;
};
struct status sbullet[5];
int x = 38, y = 27, score = 0, vec = 0, i = 0;
char ch = ' ',ch1 =' ';
void gotoxy(int, int);
void print_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void setarealr(int);
void setareatd(int);
void bullet(int, int);
void erase_bullet(int, int);
void Setup(void);
void set_enemy(int);
void show_srore(int, int, int);
void bulletmov(void);
void shipmov(int);
void shot(int, int);
void checkstatus(void);
char cursor(int, int);
void intro(void);
void deleteall(void);
int main()
{
	intro();
	do
	{
		if (_kbhit())
		{
			ch1 = _getch();
			if (ch1 == 't')
			{	
				Setup();
				do
				{
					show_srore(score, 103, 1);
					shipmov(vec);
					bulletmov();
					if (_kbhit())
					{
						ch = _getch();
						if (ch == 'a' && x > 1)
							vec = 1;
						if (ch == 'd' && x < 73)
							vec = -1;
						if (ch == 's')
							vec = 0;
						if (ch == ' ')
						{
							checkstatus();
							shot(x, y);
						}
						fflush(stdin);
					}
					Sleep(50);
				} while (ch != 'x');
				deleteall();
				intro();
			}
		}
	} while (ch1 != 'x');
	
	system("pause");
}
void checkstatus()
{
	for (i = 0; i < 5; i++)
	{
		if (sbullet[i].sta == 0)
			break;
	}
}
void shot(int a, int b)
{
	Beep(4000, 10);
	sbullet[i].bulletx = a;
	sbullet[i].bullety = b - 1;
	sbullet[i].sta = 1;
}
void shipmov(int a)
{
	if (a != 0)
	{
		if (a == 1 && x > 1)
			print_ship(--x, y);
		if (a == -1 && x < 73)
			print_ship(++x, y);
	}
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
	setcolor(2, 0);
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
	setcolor(0, 0);
	cout << " ";
}
void bullet(int x, int y)
{
	gotoxy(x + 3, y);
	setcolor(2, 0);
	cout << "^";
}
void intro()
{
	setcolor(7, 0);
	setcursor(0);
	gotoxy(20, 10); cout << "______ _____    __   ______ ______ _     _   __   _____ ";
	gotoxy(20, 11); cout << "__     _   __ __  __ _      _      _     _ __  __ _    _";
	gotoxy(20, 12); cout << " __    _  __  __  __ _      ______ _  _  _ __  __ _   _ ";
	gotoxy(20, 13); cout << "  __   _ __   ______ _      _      _ _ _ _ ______ _  _  ";
	gotoxy(20, 14); cout << "   __  _      __  __ _      ______  __ __  __  __ _   _ ";
	gotoxy(20, 15); cout << "______ _      __  __ ______ ______  _   _  __  __ _   __";
	gotoxy(20, 20); cout << "               Press 't' to Start Game";
	gotoxy(20, 21); cout << "                  Press 'x' to Exit";
}
void Setup()
{
	setcursor(0);
	gotoxy(20, 10); cout << "                                                        ";
	gotoxy(20, 11); cout << "                                                        ";
	gotoxy(20, 12); cout << "                                                        ";
	gotoxy(20, 13); cout << "                                                        ";
	gotoxy(20, 14); cout << "                                                        ";
	gotoxy(20, 15); cout << "                                                        ";
	gotoxy(20, 20); cout << "                                            ";
	gotoxy(20, 21); cout << "                                           ";
	Sleep(1000);
	srand(time(NULL));
	setarealr(0);
	setarealr(80);
	setareatd(0);
	setareatd(28);
	print_ship(x, y);
	set_enemy(40);
	setcolor(7, 0);
	gotoxy(95, 1);
	cout << "score : ";
	gotoxy(85, 3);
	cout << "A -> <<";
	gotoxy(85, 5);
	cout << "S -> Stop";
	gotoxy(85, 7);
	cout << "D -> >>";
	gotoxy(85, 9);
	cout << "Spaceber -> shoot";
	gotoxy(85, 11);
	cout << "X -> to main menu";
	gotoxy(85, 13);
	cout << "Nachawanon Phetcharaporn";
	gotoxy(85, 15);
	cout << "61010280";
}
void set_enemy(int e)
{
	int a, b;
	for (int r = 0; r < e; ++r)
	{
		a = rand() % 61 + 10;
		b = rand() % 5 + 2;
		int c = rand() % 10 + 1;
		if (cursor(a,b) == '*')
			r--;
		else
		{
			setcolor(c, 0);
			gotoxy(a, b);
			cout << "*";
		}
		
	}
}
char cursor(int x, int y) 
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}
void show_srore(int s,int a,int b)
{
	setcolor(7, 0);
	gotoxy(a, b);
	cout << s;
}
void bulletmov()
{
	for (int k = 0; k < 5; k++)
	{
		if (sbullet[k].sta == 1)
		{
			erase_bullet(sbullet[k].bulletx, sbullet[k].bullety);
			if (sbullet[k].bullety > 1)
			{
				if (cursor(sbullet[k].bulletx + 3, sbullet[k].bullety - 1) == '*')
				{
					gotoxy(sbullet[k].bulletx + 3, sbullet[k].bullety - 1);
					cout << " ";
					sbullet[k].sta = 0;
					Beep(1000, 10);
					score++;
					set_enemy(1);
				}
				else
					bullet(sbullet[k].bulletx, --sbullet[k].bullety);
			}
			else
				sbullet[k].sta = 0;
		}
	}
}
void deleteall()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			gotoxy(j, i);
			cout << " ";	
		}
	}
}