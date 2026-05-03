#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

void print_bits64(uint64_t x)
{
    for (int i = 63; i >= 0; i--) {
        printf("%d", (int)((x >> i) & 1));
        
        if (i == 63 || i == 52) {
            printf(" ");    // separa S | E | M
        }
    }
    
    printf("\n");
}
int main()
{
    double y = 222.658;
    
    uint64_t bits;
    memcpy(&bits, &y, sizeof(bits));
    
    uint64_t sign     = (bits >> 63) & 0x1;
    uint64_t exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;
    
    printf("Sinal     = %" PRIu64 "\n", sign);
    printf("Expoente  = %" PRIu64 "\n", exponent);
    printf("Mantissa  = 0x%013" PRIX64 "\n", mantissa);
    
    printf("Expoente real = %lld\n", (long long)exponent - 1023);
    
    printf("Bits:\n");
    print_bits64(bits);
    return 0;
}
