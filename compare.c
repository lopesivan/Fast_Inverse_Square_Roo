#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define N 10000000

float libm_inv_sqrt(float x)
{
    return 1.0f / sqrtf(x);
}

float fast_inv_sqrt(float x)
{
    float xhalf = 0.5f * x;
    uint32_t i;
    
    memcpy(&i, &x, sizeof(i));
    
    i = 0x5f3759df - (i >> 1);
    
    memcpy(&x, &i, sizeof(x));
    
    // Uma iteração de Newton-Raphson
    /* x = x * (1.5f - xhalf * x * x); */
    
    // duas iterações de Newton-Raphson
    x = x * (1.5f - xhalf * x * x);
    x = x * (1.5f - xhalf * x * x);
    return x;
}

double elapsed_seconds(struct timespec a, struct timespec b)
{
    return (b.tv_sec - a.tv_sec) +
           (b.tv_nsec - a.tv_nsec) / 1000000000.0;
}

int main(void)
{
    float values[] = {
        0.1f,
        0.5f,
        1.0f,
        2.0f,
        10.0f,
        222.658f,
        1000.0f
    };
    
    int nvalues = sizeof(values) / sizeof(values[0]);
    
    printf("Comparacao numerica:\n\n");
    
    for (int i = 0; i < nvalues; i++) {
        float x = values[i];
        
        float a = libm_inv_sqrt(x);
        float b = fast_inv_sqrt(x);
        
        float erro_abs = fabsf(a - b);
        float erro_rel = erro_abs / fabsf(a);
        
        printf("x = %.6f\n", x);
        printf("libm              = %.9f\n", a);
        printf("fast_inv_sqrt     = %.9f\n", b);
        printf("erro absoluto     = %.9f\n", erro_abs);
        printf("erro relativo     = %.9f %%\n", erro_rel * 100.0f);
        printf("----------------------------------\n");
    }
    
    volatile float sink = 0.0f;
    
    struct timespec t1, t2;
    
    clock_gettime(CLOCK_MONOTONIC, &t1);
    
    for (int i = 1; i <= N; i++) {
        float x = (float)i * 0.001f + 0.1f;
        sink += libm_inv_sqrt(x);
    }
    
    clock_gettime(CLOCK_MONOTONIC, &t2);
    
    double tempo_libm = elapsed_seconds(t1, t2);
    
    clock_gettime(CLOCK_MONOTONIC, &t1);
    
    for (int i = 1; i <= N; i++) {
        float x = (float)i * 0.001f + 0.1f;
        sink += fast_inv_sqrt(x);
    }
    
    clock_gettime(CLOCK_MONOTONIC, &t2);
    
    double tempo_fast = elapsed_seconds(t1, t2);
    
    printf("\nComparacao de tempo:\n\n");
    printf("Iteracoes: %d\n", N);
    printf("Tempo libm          = %.6f s\n", tempo_libm);
    printf("Tempo fast_inv_sqrt = %.6f s\n", tempo_fast);
    printf("Razao libm/fast     = %.3f\n", tempo_libm / tempo_fast);
    
    printf("\nValor anti-otimizacao: %f\n", sink);
    
    return 0;
}
