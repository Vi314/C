#include <stdio.h>
#include <string.h>
#include "main.h"
#include "../common/utils.h"

//gcc main.c ./../common/utils.c -o main && ./main.exe
int main(int argc, char const* argv[]) {
    FILE* fptr = fopen("input.txt", "r");
    char buffer[25];    
    char *destWire, *token;
    int valLeft, valRight, idx;
    while (fgets(buffer, 25, fptr)) {
        printf("\nSTR: %s \t", buffer);
        token = strtok(buffer, "-> ");
        printf("\tToken1: %s", token);
        token = strtok(NULL, "-> ");
        printf("\tToken3: %s", token);
        token = strtok(NULL, "-> ");
        printf("\tToken4: %s", token);
        
        destWire = strtok(buffer, "-> \n");
        printf("\tDestWire: %s", destWire);

        //idx = getIdx(destWire);
        //Get valLeft

        if (isLowerCaseNum(buffer[0])) {

        } else if (isDigit(buffer[0])) {
            
        } else {
            // if (strcmp(token, "AND") == 0) {
                
            // } else if (strcmp(token, "OR") == 0) {
                
            // } else if (strcmp(token, "NOT") == 0) {
                
            // } else if (strcmp(token, "LSHIFT") == 0) {

            // } else if (strcmp(token, "RSHIFT") == 0) {

            // }

        }
    }
    return 0;
}

//AND OR NOT LSHIFT RSHIFT
//97-122 => a-z 48-57 => 0-9

int getIdx(char* chptr) {
    if (chptr[1] == 0) {
        chptr[1] = 1;
    }
    return (chptr[0] % 32) * (2 * (chptr[1] % 32));
}
