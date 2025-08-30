#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int celebrity(int **mat, int n) {
    int i, j;
    int candidate = 0;

    // Find a potential celebrity
    for (i = 1; i < n; i++) {
        if (mat[candidate][i] == 1) {
            candidate = i;
        }
    }

    // Verify the candidate
    for (i = 0; i < n; i++) {
        if (i != candidate) {
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }
    }

    return candidate;
}