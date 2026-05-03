#include <stdint.h>
#include <stdio.h>
#include <string.h>

void print_bits(uint32_t x)
{
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        
        if (i == 31 || i == 23) {
            printf(" ");    // separa S | E | M
        }
    }
    
    printf("\n");
}

int main()
{
    float y = 6.625f;
    
    uint32_t bits;
    memcpy(&bits, &y, sizeof(bits)); // forma segura
    
    // Extrair campos
    uint32_t sign = (bits >> 31) & 0x1;
    uint32_t exponent = (bits >> 23) & 0xFF;
    uint32_t mantissa = bits & 0x7FFFFF;
    
    printf("Valor: %f\n\n", y);
    
    printf("Bits completos:\n");
    print_bits(bits);
    
    printf("\nCampos:\n");
    printf("Sinal     = %u\n", sign);
    printf("Expoente  = %u (com bias)\n", exponent);
    printf("Mantissa  = 0x%06X\n", mantissa);
    
    printf("\nExpoente real = %d\n", (int)exponent - 127);
    
    return 0;
}
