#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <strings.h>
#include "md5.h"

int main(int argc, char const* argv[]) {
    char input[] = "bgvyzdsv";
    char buffer[30];
    char hexbuffer[50];
    long int number = 0;
    char numberstr[20];
    uint8_t result[16];
    while (number < 200000000000) {
        sprintf(numberstr, "%d", number);
        strcpy(buffer, input);
        strcat(buffer, numberstr);
        md5String(buffer, result);
        to_hex(hexbuffer, sizeof(hexbuffer), result, sizeof(result));
        bool allZero = true;
        for (int i = 0; i < 6; i++) {
            if (hexbuffer[i] != '0') {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            printf("Number: %d\n", number);
            print_hash(result);
            break;
        }
        memset(buffer, 0, 30);
        memset(hexbuffer, 0, 50);
        memset(numberstr, 0, 20);
        number++;
    }

    return 0;
}

int to_hex(char* dest, size_t dest_len, const uint8_t* values, size_t val_len) {
    if (dest_len < (val_len * 2 + 1))
        return 0;
    *dest = '\0';
    while (val_len--) {
        sprintf(dest, "%02X", *values);
        dest += 2;
        ++values;
    }
    return 1;
}


void print_hash(uint8_t* p) {
    for (unsigned int i = 0; i < 16; ++i) {
        printf("%02x", p[i]);
    }
    printf("\n");
}