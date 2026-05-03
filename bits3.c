#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_bits64(uint64_t x) {
    for (int i = 63; i >= 0; i--) {
        printf("%d", (int)((x >> i) & 1));

        if (i == 63 || i == 52) printf(" "); // separa S | E | M
    }
    printf("\n");
}

int main() {
    double y = 222.658;

    uint64_t bits;
    memcpy(&bits, &y, sizeof(bits));

    uint64_t sign     = (bits >> 63) & 0x1;
    uint64_t exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;

    printf("Valor: %.15f\n\n", y);

    printf("Bits:\n");
    print_bits64(bits);

    printf("\nCampos:\n");
    printf("Sinal     = %llu\n", sign);
    printf("Expoente  = %llu\n", exponent);
    printf("Mantissa  = 0x%013llX\n", mantissa);

    printf("\nExpoente real = %lld\n", (long long)exponent - 1023);

    return 0;
}
