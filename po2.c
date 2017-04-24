#include <stdio.h>
#include <stdlib.h>

int powerOfTwo(int);

int main(int argc, char *argv[]) {
    if (argc < 2)
        return -1;

    int input = atoi(argv[1]);
    _Bool isPowerOfTwo = powerOfTwo(input);

    if (isPowerOfTwo)
        printf("%s\n", "true");
    else
        printf("%s\n", "false");

    return 0;
}

int powerOfTwo(int input) {
    if (input == 1 || (input <<= 2) % 2 == 0) {
        return 1;
    }
    return 0;
}
