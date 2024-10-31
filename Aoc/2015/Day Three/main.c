#include <stdio.h>
#include <stdlib.h>

struct position {
    int x;
    int y;
};

int main(int argc, char const* argv[]) {
    FILE* fptr = fopen("input.txt", "r");
    struct position positions[10000];
    struct position santaPosition = {0, 0};
    struct position robotPosition = {0, 0};
    struct position *currentPosition;    
    int isRobotTime = 0;
    int i = 0;
    char ch = fgetc(fptr);
    while (ch > 0) {
        currentPosition = isRobotTime == 1 ? &robotPosition : &santaPosition;
        if (ch == '^') {
            currentPosition->x++;
        } else if (ch == 'v') {
            currentPosition->x--;
        } else if (ch == '<') {
            currentPosition->y--;
        } else if (ch == '>') {
            currentPosition->y++;
        }
        int exists = 0;
        for (int z = 0; z < i; z++) {
            if (positions[z].x == currentPosition->x && positions[z].y == currentPosition->y) {
                exists = 1;
                break;
            }
        }
        if (exists == 0) {
            positions[i] = *currentPosition;
            i++;
        }
        isRobotTime = !isRobotTime;
        ch = fgetc(fptr);
    }
    printf("Number of houses visited: %d", i);
    return 0;
}

