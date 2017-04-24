#include <stdio.h>
#include <stdlib.h>

#define DIM 4

int main(int argc, char const *argv[]) {
    int m[DIM][DIM][DIM] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        },
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        },
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        },
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        }
    };

    for (int x = 0; x < DIM; x++) {
        for (int y = 0; y < DIM; y++) {
            for (int z = 0; z < DIM; z++) {
                printf("%2d\t", m[x][y][z]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
