#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fptr = fopen("input.txt", "r");
    char ch = fgetc(fptr);
    int x = 0;
    int y = 0;

    while (ch > 0)
    {
        if (ch == '^')
        {
            x++;
        }
        if (ch == 'v')
        {
            x--;
        }
        if (ch == '<')
        {
            y--;
        }
        if (ch == '>')
        {
            y++;
        }
        ch = fgetc(fptr);
    }
    printf("Houses visited: x: %d y: %d", x, y);
    return 0;
}
