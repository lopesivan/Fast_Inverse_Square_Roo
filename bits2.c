#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_bits(uint32_t x)
{
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        
        if (i == 31 || i == 23) {
            printf(" ");
        }
    }
    
    printf("\n");
}

int main()
{
    float y = -6.625f;
    uint32_t bits;
    
    memcpy(&bits, &y, sizeof(bits));
    
    printf("Original:\n");
    print_bits(bits);
    printf("y = %f\n\n", y);
    
    // Extrair expoente
    uint32_t exponent = (bits >> 23) & 0xFF;
    
    // Subtrair 1 do expoente (dividir por 2)
    exponent -= 1;
    
    // Recolocar no número
    bits &= ~(0xFF << 23);         // limpa expoente
    bits |= (exponent << 23);      // novo expoente
    
    float result;
    memcpy(&result, &bits, sizeof(result));
    
    printf("Depois de dividir por 2 (via expoente):\n");
    print_bits(bits);
    printf("resultado = %f\n", result);
    
    return 0;
}
