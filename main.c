//License MIT 2017 Ahmad Retha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multi-shift-and.h"

int main(int argc, char ** argv)
{
    if (argc < 3) {
        fprintf(stderr, "Too few Arguments!\n");
        fprintf(stderr, "Usage: ./multi-shift-and TEXT PATTERN1 [PATTERN2 ...]\n");
        return 1;
    }
    unsigned int n = strlen(argv[1]);
    unsigned int m = 0;

    unsigned int i, j;
    for (i = 2; i < argc; i++)
    {
        j = strlen(argv[i]);
        if (j > n) {
            fprintf(stderr, "Patterns must be shorter than the text!\n");
            return 1;
        } else {
            m += j;
        }
    }

    if (m > BITSINWORD) {
        fprintf(stderr, "Total pattern length is too long! Limit is %d\n", (int)BITSINWORD);
        return 1;
    }

    search(argv[1], n, &(argv[2]), argc - 2);

    return 0;
}
