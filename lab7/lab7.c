#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_bullet(int x, int y)
{
    gotoxy(x, y);
    Beep(1000, 50);
    printf(".");
}

void draw_ship(int x, int y)
{
    gotoxy(x, y);
    printf(" <-0-> ");
}

void clear_bullet(int x, int y)
{
    gotoxy(x, y);
    printf(" ");
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x, y};
    DWORD num_read;
    if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
    {
        return '\0';
    }

    else
    {
        return buf[0];
    }
}

void draw_star()
{
    int dx, dy;
    while (1)
    {
        dx = (rand() % 69) + 10;
        dy = (rand() % 4) + 2;
        if (cursor(dx, dy) != '*')
        {
            break;
        }
    }

    gotoxy(dx, dy);
    printf("*");
}


int main()
{
    char ch = '.';
    int x = 40;
    int y = 20;
    int bx, by, i;
    int bullet = 0;
    int star = 0;
    int sc = 0;
    srand(time(NULL));
    while (star < 20)
    {
        draw_star();
        star++;
    }

    draw_ship(x, y);
    do
    {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a' && x != 0)
            {
                draw_ship(--x, y);
            }
            if (ch == 's' && x != 73)
            {
                draw_ship(++x, y);
            }
            if (bullet != 1 && ch == ' ')
            {
                bullet = 1;
                bx = x + 2;
                by = y - 1;
            }
            fflush(stdin);
        }
        if (bullet == 1)
        {

            clear_bullet(bx, by);
            if (by == 0)
            {
                bullet = 0;
            }
            else if (cursor(bx, by - 1) == '*')
            {
                clear_bullet(bx, by - 1);
                bullet = 0;
                draw_star();
                Beep(100, 50);
            }
            else
            {
                draw_bullet(bx, --by);
                Beep(1000, 50);
            }
        }
    } 
    while (ch != 'x');
    return 0;
    
    
}