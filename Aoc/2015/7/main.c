#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "../common/utils.h"

//gcc main.c ./../common/utils.c -o main && ./main.exe
//AND OR NOT LSHIFT RSHIFT
//97-122 => a-z 48-57 => 0-9

int wires[1250];

int main(int argc, char const* argv[]) {
    FILE* fptr = fopen("input.txt", "r");
    char buffer[40];
    char* next, *token;
    int val, secondVal, idx;
    int indexOfa;
    while (fgets(buffer, 25, fptr)) {
        token = strtok(buffer, " \n");
        while (token != NULL) {
            if (isLowerCaseNum(token[0])) {
                val = wires[getIdx(token)];
            } else if (isDigit(token[0])) {
                val = strtol(token, NULL, 10);
            } 
            else if (isUpperCaseNum(token[0])) {
                next = strtok(NULL, " \n");
                if (isLowerCaseNum(next[0])) {
                    secondVal = wires[getIdx(next)];
                } else if (isDigit(next[0])) {
                    secondVal = strtol(next, NULL, 10);
                }
                
                if (strcmp(token, "AND") == 0) {
                    val = val & secondVal;
                } else if (strcmp(token, "OR") == 0) {
                    val = val | secondVal;
                } else if (strcmp(token, "NOT") == 0) {
                    val = secondVal;
                } else if (strcmp(token, "LSHIFT") == 0) {
                    val = val << secondVal;
                } else if (strcmp(token, "RSHIFT") == 0) {
                    val = val >> secondVal;
                }
            } else if (strcmp(token, "->") == 0) {
                token = strtok(NULL, " \n");
                idx = getIdx(token);
                wires[idx] = val;
                break;
            }
            token = strtok(NULL, " \n");
        }
    }

    printf("Value of [a]: %d", wires[0]);
    return 0;
}

int getIdx(char* chptr) {
    if (chptr[1] == '\0') {
        return chptr[0] - 'a'; // Single character wire
    } else {
        return (chptr[0] - 'a') * 26 + (chptr[1] - 'a'); // Double character wire
    }
}