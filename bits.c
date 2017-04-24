#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bits.h"


int main(int argc, char *argv[]) {
    char mode = argc >= 2 ? argv[1][0] : 't';
    short bits = argc >= 3 ? atoi(argv[2]) : DEFAULT_BITS;
    char *value;
    long position;

    switch (mode) {
        case 'c':
            value = argc == 4 ? argv[3] : "00000000";
            printf("%s\n", value);
            conversion(bits, value);
            break;
        case 't':
        default:
            position = argc == 4 ? atol(argv[3]) : -1;
            bit_table(bits, position);
            break;
    }

    return 0;
}

void conversion(short bits, char *value) {
    long convertedValue = convert_from_bits(value, bits);
    printf("%li\n", convertedValue);
}

long convert_from_bits(char *value, short bits) {
    return (long) strtol(value, NULL, 2);
}

void bit_table(short bits, long position) {

        long range = pow(2, bits);
        long numbers[range];

        for(long i = 0; i < range; i++)
            numbers[i] = i;

        if(position >= 0)
            print_bits(numbers[position], bits);
        else
            for(int i = 0; i < range; i++)
                print_bits(numbers[i], bits);
}

void print_bits(long number, short bits){
    short maxPow = 1 << (bits - 1);
    long shiftedNumber = number;

    for(int i = 0; i < bits; i++) {
        if(i > 0 && i % 4 == 0)
            printf(" ");

        printf("%u", shiftedNumber & maxPow ? 1 : 0);
        shiftedNumber <<= 1;
    }
    printf("\t#%6li\n", number);
}
