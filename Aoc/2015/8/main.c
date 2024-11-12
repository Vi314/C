#include <stdio.h>

//Messed up code to fix later
int main(int argc, char const* argv[]) {
    FILE* file = fopen("input.txt", "r");
    int actualCount, totalCount;
    char ch;
    char whitespace[] = { '\n', '\r', ' ' };
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(file);
        totalCount++;
        for (int i = 0; i < 3; i++) {
            if (ch == whitespace[i]) {
                continue;
            }
        }
        if (ch == '\\') {
            ch = fgetc(file);
            if (ch == 'x') {
                fseek(file, 1, SEEK_CUR);
                totalCount++;
            }
            actualCount++;
        } else if (ch == "\"") {
            continue;
        } else {
            actualCount++;
        } 
    }

    printf("\nActualCount:%d-TotalCount:%d", actualCount, totalCount);
    return 0;
}
