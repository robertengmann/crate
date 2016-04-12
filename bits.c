#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define DEFAULT_BITS 8

void print_bits_at_position(long *, long, short);

int main(int argc, char *argv[]) {
    short bits = argc >= 2 ? atoi(argv[1]) : DEFAULT_BITS;
    long position = argc == 3 ? atol(argv[2]) : -1;

    long range = pow(2, bits);
    long numbers[range];

    for(long i = 0; i < range; i++) {
        numbers[i] = i;
    }

    if(position >= 0) {
        print_bits_at_position(numbers, position, bits);
    } else {
        for(int i = 0; i < range; i++) {
            print_bits_at_position(numbers, i, bits);
        }
    }

    return 0;
}

void print_bits_at_position(long *numbers, long position, short bits) {
    short maxPow = 1 << (bits - 1);
    long num = numbers[position];

    for(int j = 0; j < bits; j++){
        if(j > 0 && j % 4 == 0) {
            printf(" ");
        }
        printf("%u", num & maxPow ? 1 : 0);
        num <<= 1;
    }
    printf("\t#%6d\n", position);
}

