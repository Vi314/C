#include <stdio.h>
#include "main.h"

//This code is the tale of a man who feared regex enough to write string matching logic manually.
int main(int argc, char const* argv[]) {
    //PartOne();
    FILE* fptr = fopen("input.txt", "r");
    char word[18];
    int validCount = 0;
    while (fgets(word, 18, fptr)) {
        int repeatsWithJump = 0;
        for (int i = 0; i < 14; i++) {
            if (word[i] == word[i + 2]) {
                repeatsWithJump++;
                break;
            }
        }
        if (!repeatsWithJump) {
            continue;
        }

        int repeatingCoupleExists = 0;
        for (int i = 0; i < 15; i++) {
            char charCouple[] = { word[i], word[i + 1] };
            for (int z = i + 2; z < 15; z++) {
                if (word[z] == charCouple[0] && word[z+1] == charCouple[1]) {
                    repeatingCoupleExists++;
                    break;
                }
            }
            if (repeatingCoupleExists) {
                break;
            }
        }
        if (!repeatingCoupleExists) {
            continue;
        }
        validCount++;
    }

    printf("Valid count: %d", validCount);
    return 0;
}


void PartOne() {
    FILE* fptr = fopen("input.txt", "r");
    char word[18];
    int validCount = 0;
    while (fgets(word, 18, fptr)) {
        //We check for the vowel(aeiou) amount in the word
        int vowelCount = 0;
        for (int i = 0; i < 16; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                vowelCount++;
            }
        }
        if (vowelCount < 3) {
            continue;
        }

        //We check for a repeating char to exist
        int hasRepeatingChar = 0;
        for (int i = 0; i < 15; i++) {
            if (word[i] == word[i + 1]) {
                hasRepeatingChar += 1;
                break;
            }
        }
        if (!hasRepeatingChar) {
            continue;
        }

        //We check for illegal char couples (ab, cd, pq, or xy)
        int illegalCharCoupleExists = 0;
        for (int i = 0; i < 15; i++) {
            if (illegalCharCoupleExists == 1) {
                break;
            }

            if (word[i] == 'a' && word[i + 1] == 'b') {
                illegalCharCoupleExists++;
            }
            if (word[i] == 'c' && word[i + 1] == 'd') {
                illegalCharCoupleExists++;
            }
            if (word[i] == 'p' && word[i + 1] == 'q') {
                illegalCharCoupleExists++;
            }
            if (word[i] == 'x' && word[i + 1] == 'y') {
                illegalCharCoupleExists++;
            }
        }

        if (illegalCharCoupleExists) {
            continue;
        }

        //Glory to the word whom survives the trials, we increase the valid count by one in celebration.
        validCount++;
    }
    printf("Final count: %d", validCount);

    /*
        //bitmask impl done for vowel checking completely because of a misunderstanding
        //We check for vowels(aeiou) using a bit mask because we are cool like that
        int vowelMap = 0x0;
        for (int i = 0; i < 16; i++) {
            switch (word[i]) {
            case 'a':
                vowelMap |= 1 << 0;
                break;
            case 'e':
                vowelMap |= 1 << 1;
                break;
            case 'o':
                vowelMap |= 1 << 2;
                break;
            case 'u':
                vowelMap |= 1 << 3;
                break;
            case 'i':
                vowelMap |= 1 << 4;
                break;
            }
        }
        int repeatedCount = 0;
        for (int i = 0; i < 5; i++) {
            if (vowelMap & (1 << i)) {
                repeatedCount++;
            }
        }
        if (repeatedCount < 3) {
            continue;
        }
    */
}

