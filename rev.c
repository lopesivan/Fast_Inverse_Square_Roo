#include <stdio.h>
#include <stdint.h>
#include <string.h>

float build_float(uint32_t sign, uint32_t exponent, uint32_t mantissa)
{
    uint32_t bits;
    
    bits = (sign << 31) |
           (exponent << 23) |
           mantissa;
           
    float result;
    memcpy(&result, &bits, sizeof(result));
    
    return result;
}

int main(void)
{
    /*
    Sabemos:
    
    6.625 = 1.10101 × 2²
    
    Então:
    
    S = 0
    E = 2 + 127 = 129 → 10000001
    M = 10101 → 10101000000000000000000
    
    */
    
    uint32_t sign = 0;
    uint32_t exponent = 129;
    uint32_t mantissa = 0b10101000000000000000000;
    
    float x = build_float(sign, exponent, mantissa);
    
    printf("x = %f\n", x);
    
    return 0;
}
