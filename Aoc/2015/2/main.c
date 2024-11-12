#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

int main(int argc, char const *argv[]) //bro chat gpt wrote this :(
{
    FILE *fileptr = fopen("input.txt", "r");
    if (fileptr == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    int requiredPaper = 0;
    int requiredWrap = 0;
    int l, w, h;

    while (fscanf(fileptr, "%dx%dx%d", &l, &w, &h) == 3)
    {
        int paperArea = calculateWrappingPaper(l, w, h);
        int slack = calculateSlack(l, w, h);
        
        int ribbon = calculateRibbon(l, w, h);
        int bow = l * w * h;
        //printf("Dimensions : %dx%dx%d, Area: %d, Slack: %d\n", l, w, h, paperArea, slack);
        
        requiredWrap += ribbon + bow;
        requiredPaper += paperArea + slack;
    }

    printf("\nTotal Required Wrap: %d\n", requiredWrap);
    printf("\nTotal Required Paper: %d\n", requiredPaper);
    fclose(fileptr);
    return 0;
}

int calculateRibbon(int l, int w, int h)
{
    if (l >= w && l >= h)
        return w + w + h + h;
    else if (w >= l && w >= h)
        return l + l + h + h;
    else
        return l + l + w + w;
}

int calculateSlack(int l, int w, int h)
{
    if (l >= w && l >= h)
        return w * h;
    else if (w >= l && w >= h)
        return l * h;
    else
        return l * w;
}

// int main(int argc, char const *argv[]) //My obviously superior solution that did absolutely not work
// {
//     FILE *fileptr;
//     fileptr = fopen("input.txt", "r");
//     char buffer[15];
//     int requiredPaper = 0;
//     while (fgets(buffer, 15, fileptr))
//     {
//         int *nums = (int *)malloc(3 * sizeof(int));
//         int offset = 0;
//         int numsIdx = 0;
//         for (int i = 0; i < 15 && numsIdx < 3; i++)
//         {
//             if (buffer[i] <= 47 || buffer[i] >= 58)
//             {
//                 int numLength = i - offset;
//                 char numBuffer[numLength];
//                 memcpy(numBuffer, buffer + offset, numLength * sizeof(char));
//                 int num = chartoint(numBuffer);
//                 nums[numsIdx] = num;
//                 numsIdx++;
//                 offset = i + 1;
//             }
//         }
//         int paperArea = calculateWrappingPaper(nums[0], nums[1], nums[2]);
//         int slack = calculateSlack(nums);
//         requiredPaper += paperArea + slack;
//         free(nums);
//         //printf("X: %d, Y: %d, Z: %d, Area: %d, Slack %d\n", nums[0], nums[1], nums[2], paperArea, slack);
//     }
//     printf("\nRequired Paper: %d\n", requiredPaper);
//     return 0;
// }

// int calculateSlack(int *dimensions)
// {
//     int slack = 0;
//     if (dimensions[0] < dimensions[1] || dimensions[0] < dimensions[2])
//     {
//         slack = dimensions[0];
//     }
//     if (slack > 0)
//     {
//         if (dimensions[1] > dimensions[2])
//         {
//             slack *= dimensions[2];
//         }
//         else
//         {
//             slack *= dimensions[1];
//         }
//     }
//     else
//     {
//         slack = dimensions[1] * dimensions[2];
//     }

//     return slack;
// }

int calculateWrappingPaper(int l, int w, int h)
{
    return (2 * l * w) + (2 * w * h) + (2 * h * l);
}

int chartoint(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; isdigit(s[i]); ++i)
    {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}