#include<stdio.h>
#include<windows.h>
#include<conio.h>
void draw_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("       ");
}

int main() {
	char ch = ' ';
	int x = 0, y = 15;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x = 0)
			{
				erase_ship(x, y);
				draw_ship(--x, y);
			}
			else if (ch == 'd' && x <= 73)
			{
				erase_ship(x, y);
				draw_ship(++x, y);
			}
			else if (ch == 'w' && y = 0)
			{
				erase_ship(x, y);
				draw_ship(x, --y);
			}
			else if (ch == 's' && y <= 80)
			{
				erase_ship(x, y);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}

	} while (ch != 'x');
	return 0;
}
