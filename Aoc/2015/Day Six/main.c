#include <stdio.h>

int grid[1000][1000];

typedef struct {
    int x;
    int y;
} Pos;

int main(int argc, char const* argv[]) {
    FILE* fptr = fopen("input.txt", "r");
    char buffer[40];
    char move[10];
    Pos left, right;
    while (fgets(buffer, 40, fptr)) {
        sscanf(buffer, "%[^0-9]%d,%d through %d,%d", move, &left.x, &left.y, &right.x, &right.y);
        // printf("%s> %d => %d, %d => %d\n", move, left.x, right.x, left.y, right.y);
        for (int i = left.x; i <= right.x; i++) {
            for (int z = left.y; z <= right.y; z++) {
                if (move[6] == 'n') { //turn o(n)
                    grid[i][z]++;
                } else if (move[6] == 'f') { //turn o(f)f
                    if (grid[i][z] > 0) {
                        grid[i][z]--;
                    }
                } else if (move[5] == 'e') { //toggl(e)
                    grid[i][z] += 2;
                }
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < 1000; i++) {
        for (int z = 0; z < 1000; z++) {
            counter += grid[i][z];
        }
    }
    printf("Total Brightness: %d", counter);
    return 0;
}

