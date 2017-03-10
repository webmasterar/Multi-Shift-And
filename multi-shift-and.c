//License MIT 2017 Ahmad Retha

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "multi-shift-and.h"

/**
 * Preprocess all the patterns letter positions into bitvector array B.
 *
 * @param B The bitvector storing the positions of each character of the patterns
 * @param patterns The patterns to processes
 * @param c How many patterns there are
 * @return z The final-state bitvector
 */
WORD preprocess(WORD ** B, char ** patterns, unsigned int c)
{
    WORD z = 0;

    unsigned int i = 0, j = 0, k, m;
    for (; i < c; i++)
    {
        m = strlen(patterns[i]);
        z = (z << m) | (1ul << (m-1));
        for (k = 0; k < m; k++, j++)
        {
            (*B)[(int)patterns[i][k]] = (*B)[(int)patterns[i][k]] | (1ul << j);
        }
    }

    return z;
}

/**
 * Search a text with multiple patterns using the multi-shift-and algorithm.
 *
 * @param t The text
 * @param n The length of the text
 * @param patterns The patterns to search for
 * @param c How many patterns there are
 */
void search(char * t, unsigned int n, char ** patterns, unsigned int c)
{
    WORD * B = (WORD *) calloc(CHARLIMIT, WORDSIZE); //B bitvector array holds all letters and their positions
    WORD z = preprocess(&B, patterns, c); //z holds all ending positions of matches
    WORD d = 0; //d holds the match state at any given point in the search
    WORD f = 0; //f is for holding initial state of patterns (their starting positions)

    //update f to hold initial state marking all starting positions of the patterns
    unsigned int i, m;
    for (i = 0; i < c; i++) {
        m = strlen(patterns[i]);
        f = (f << m) | 1ul;
    }

    //do the search
    unsigned int matchFound = 0;
    for (i = 0; i < n; i++) {
        d = ((d << 1) | f) & B[(int)t[i]];
        if (d & z) {
            matchFound = 1;
            printf("Match found ending at position %u\n", i);
        }
    }

    if (matchFound == 0) {
        printf("No matches found!\n");
    }

    free(B);
}
