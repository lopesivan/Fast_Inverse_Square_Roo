/* gcc 3d.c -o 3d -O3 -Wall -Wextra -lm


$ ./3d
Vetor original:
(3.000000, 4.000000, 5.000000)

FAST:
(0.424263954, 0.565685272, 0.707106590)
length = 0.999999702

LIBM:
(0.424264073, 0.565685451, 0.707106769)
length = 1.000000000

ivan*:  /workspace/obs/Fast_Inverse_Square_Roo main !1 ?2
$ echo "scale=9; m=3*3 +4*4 +5*5; m=sqrt(m); 3/m;4/m;5/m" | bc
.424264068
.565685425
.707106781






*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x, y, z;
} vec3;

// Fast inverse sqrt
float fast_inv_sqrt(float x)
{
    float xhalf = 0.5f * x;
    uint32_t i;
    
    memcpy(&i, &x, sizeof(i));
    i = 0x5f3759df - (i >> 1);
    memcpy(&x, &i, sizeof(x));
    
    // 2 iterações (boa precisão)
    x = x * (1.5f - xhalf * x * x);
    x = x * (1.5f - xhalf * x * x);
    
    return x;
}

// Normalização usando fast
vec3 normalize_fast(vec3 v)
{
    float len2 = v.x * v.x + v.y * v.y + v.z * v.z;
    float inv_len = fast_inv_sqrt(len2);
    
    vec3 r = {
        v.x * inv_len,
        v.y * inv_len,
        v.z* inv_len
    };
    
    return r;
}

// Normalização usando libm
vec3 normalize_libm(vec3 v)
{
    float len = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    
    vec3 r = {
        v.x / len,
        v.y / len,
        v.z / len
    };
    
    return r;
}

// comprimento (para verificar)
float length(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

int main(void)
{
    vec3 v = {3.0f, 4.0f, 5.0f};
    
    vec3 a = normalize_fast(v);
    vec3 b = normalize_libm(v);
    
    printf("Vetor original:\n");
    printf("(%.6f, %.6f, %.6f)\n\n", v.x, v.y, v.z);
    
    printf("FAST:\n");
    printf("(%.9f, %.9f, %.9f)\n", a.x, a.y, a.z);
    printf("length = %.9f\n\n", length(a));
    
    printf("LIBM:\n");
    printf("(%.9f, %.9f, %.9f)\n", b.x, b.y, b.z);
    printf("length = %.9f\n\n", length(b));
    
    return 0;
}
