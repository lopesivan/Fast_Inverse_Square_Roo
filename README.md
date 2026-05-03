# Raiz Quadrada Inversa Rápida Explicada

O vídeo explica a história e o funcionamento matemático por trás de um dos algoritmos mais famosos da computação: o **Fast Inverse Square Root** (Raiz Quadrada Inversa Rápida), que ficou célebre ao ser descoberto no código-fonte de *Quake III Arena*.

Aqui está um resumo detalhado dos pontos principais abordados:

### 1. O Problema: Por que calcular $1/\sqrt{x}$?
Em motores de jogos, esse cálculo é fundamental para a **normalização de vetores**. Para calcular efeitos de iluminação, reflexos e física, os vetores precisam ter comprimento unitário (igual a 1).
*   Tradicionalmente, isso exige elevar os componentes ao quadrado, somá-los, tirar a raiz quadrada e depois dividir 1 por esse resultado.
*   O problema é que, na época do lançamento do jogo, operações de **divisão** e **raiz quadrada** eram extremamente lentas para o hardware processar milhares de vezes por segundo.

### 2. O "Truque de Magia": O Número Hexadecimal `0x5f3759df`
O algoritmo chamou a atenção por conter uma linha de código incompreensível à primeira vista, que envolve um número mágico constante. O vídeo divide a explicação em três etapas principais:

#### Etapa 1: "Evil Bit Hack" (Manipulação de Endereço)
*   O algoritmo interpreta os bits de um número de ponto flutuante (*float*) como se fossem um número inteiro (*long*).
*   Isso é feito através de um truque de ponteiros em C para evitar que o compilador converta o valor; o objetivo é acessar a representação binária bruta do padrão **IEEE 754**.

#### Etapa 2: A Matemática dos Logaritmos e o Número Mágico
*   O vídeo explica que, devido à forma como os computadores armazenam números decimais (mantissa e expoente), a representação binária de um *float* é, na verdade, uma aproximação do seu próprio **logaritmo**.
*   Matematicamente, calcular a raiz quadrada inversa de $y$ é o mesmo que calcular $y^{-1/2}$. Usando logaritmos: $\log(y^{-1/2}) = -1/2 \log(y)$.
*   O algoritmo faz exatamente isso: ele desloca os bits para a direita (o que equivale a dividir por 2 no mundo binário) e subtrai esse valor do número mágico `0x5f3759df`. Esse número serve para compensar as constantes de erro e o deslocamento do padrão IEEE 754.

#### Etapa 3: Refinamento com o Método de Newton
*   O resultado da etapa anterior é uma aproximação muito boa, mas não perfeita.
*   Para aumentar a precisão sem sacrificar a performance, o algoritmo aplica uma única iteração do **Método de Newton**, uma técnica de cálculo para encontrar raízes de funções.
*   Isso reduz o erro para menos de 1%, o que é suficiente para os gráficos de um videogame.

### Conclusão
O algoritmo é considerado genial porque substitui operações pesadas de hardware por manipulações de bits simples e uma constante matemática precisa. Ele chega a ser **três vezes mais rápido** que os métodos convencionais da época, permitindo que o jogo rodasse de forma fluida mesmo em hardware limitado.

O vídeo destaca que hoje em dia existem instruções de hardware específicas para isso, mas o algoritmo de *Quake III* permanece como um marco de otimização criativa na programação.
http://googleusercontent.com/youtube_content/1


O vídeo explica a história e o funcionamento matemático por trás de um dos algoritmos mais famosos da computação: o **Fast Inverse Square Root** (Raiz Quadrada Inversa Rápida), que ficou célebre ao ser descoberto no código-fonte de *Quake III Arena*.

Aqui está um resumo detalhado dos pontos principais abordados:

### 1. O Problema: Por que calcular $1/\sqrt{x}$?
Em motores de jogos, esse cálculo é fundamental para a **normalização de vetores**. Para calcular efeitos de iluminação, reflexos e física, os vetores precisam ter comprimento unitário (igual a 1).
*   Tradicionalmente, isso exige elevar os componentes ao quadrado, somá-los, tirar a raiz quadrada e depois dividir 1 por esse resultado.
*   O problema é que, na época do lançamento do jogo, operações de **divisão** e **raiz quadrada** eram extremamente lentas para o hardware processar milhares de vezes por segundo.

### 2. O "Truque de Magia": O Número Hexadecimal `0x5f3759df`
O algoritmo chamou a atenção por conter uma linha de código incompreensível à primeira vista, que envolve um número mágico constante. O vídeo divide a explicação em três etapas principais:

#### Etapa 1: "Evil Bit Hack" (Manipulação de Endereço)
*   O algoritmo interpreta os bits de um número de ponto flutuante (*float*) como se fossem um número inteiro (*long*).
*   Isso é feito através de um truque de ponteiros em C para evitar que o compilador converta o valor; o objetivo é acessar a representação binária bruta do padrão **IEEE 754**.

#### Etapa 2: A Matemática dos Logaritmos e o Número Mágico
*   O vídeo explica que, devido à forma como os computadores armazenam números decimais (mantissa e expoente), a representação binária de um *float* é, na verdade, uma aproximação do seu próprio **logaritmo**.
*   Matematicamente, calcular a raiz quadrada inversa de $y$ é o mesmo que calcular $y^{-1/2}$. Usando logaritmos: $\log(y^{-1/2}) = -1/2 \log(y)$.
*   O algoritmo faz exatamente isso: ele desloca os bits para a direita (o que equivale a dividir por 2 no mundo binário) e subtrai esse valor do número mágico `0x5f3759df`. Esse número serve para compensar as constantes de erro e o deslocamento do padrão IEEE 754.

#### Etapa 3: Refinamento com o Método de Newton
*   O resultado da etapa anterior é uma aproximação muito boa, mas não perfeita.
*   Para aumentar a precisão sem sacrificar a performance, o algoritmo aplica uma única iteração do **Método de Newton**, uma técnica de cálculo para encontrar raízes de funções.
*   Isso reduz o erro para menos de 1%, o que é suficiente para os gráficos de um videogame.

### Conclusão
O algoritmo é considerado genial porque substitui operações pesadas de hardware por manipulações de bits simples e uma constante matemática precisa. Ele chega a ser **três vezes mais rápido** que os métodos convencionais da época, permitindo que o jogo rodasse de forma fluida mesmo em hardware limitado.

O vídeo destaca que hoje em dia existem instruções de hardware específicas para isso, mas o algoritmo de *Quake III* permanece como um marco de otimização criativa na programação.
http://googleusercontent.com/youtube_content/1


A origem exata do número **0x5f3759df** é um dos maiores mistérios da história da computação, mas a matemática por trás dele é bem sólida e explicável.

Para entender de onde ele veio, precisamos olhar para como um número decimal (**float**) é guardado no computador seguindo o padrão **IEEE 754**.

---

## 1. A Estrutura do Float
Um float de 32 bits não é um número inteiro; ele é guardado como se fosse uma notação científica:
$$V = (1 + M) \times 2^{E - 127}$$
Onde:
*   **M** é a Mantissa (os decimais).
*   **E** é o Expoente.



## 2. O Truque do Logaritmo
Quando o código faz o "Evil Bit Hack" e trata o float como um inteiro ($L$), o valor desse inteiro é aproximadamente:
$$L \approx 2^{23} \times (E - 127 + M)$$
Os matemáticos notaram que essa estrutura binária se comporta de forma muito parecida com uma **função logarítmica**. Ou seja, o valor inteiro dos bits de um float é proporcional ao $\log_2$ desse número.

Como queremos calcular $y = \frac{1}{\sqrt{x}}$, que é o mesmo que $y = x^{-1/2}$, aplicamos o logaritmo:
$$\log_2(y) = -\frac{1}{2} \log_2(x)$$

## 3. O Surgimento da Constante
Ao substituir a relação entre os bits e o logaritmo na equação acima, chegamos a uma fórmula para os bits do resultado ($I_y$):
$$I_y \approx \frac{3}{2} \cdot 2^{23}(127 - \sigma) - \frac{1}{2} I_x$$

O número mágico **0x5f3759df** é justamente o resultado desse cálculo: $$\frac{3}{2} \cdot 2^{23}(127 - \sigma)$$
*   O $\sigma$ é um fator de ajuste para minimizar o erro da aproximação.
*   Se você calcular isso com um $\sigma$ ideal, chegará muito perto de **1.597.463.007** em decimal, que em hexadecimal é o nosso famoso **0x5f3759df**.

---

## Quem o "descobriu"?
Embora o código tenha ficado famoso com o **John Carmack** em *Quake III*, ele não o inventou.
*   A investigação histórica aponta para **Gary Tarolli** (que trabalhou na 3dfx), mas ele mesmo disse que se baseou em métodos que circulavam entre programadores de computação gráfica nos anos 80 e 90.
*   O valor específico pode ter sido encontrado por **tentativa e erro** ou usando algoritmos de busca para encontrar qual número minimizava o erro médio em uma vasta gama de valores.

Curiosamente, pesquisadores posteriores descobriram que existe um número ligeiramente melhor (**0x5f375a86**), mas a diferença de precisão é tão minúscula que o original de Quake continua sendo a "lenda".


Perfeito, vamos construir a lógica do zero. Como você domina C++ e variáveis complexas, essa estrutura algébrica será bem natural para você.

O objetivo é encontrar $y = \frac{1}{\sqrt{x}}$, que podemos escrever como $y = x^{-1/2}$.

### Etapa 1: A Transformação Logarítmica
Para fugir da raiz quadrada (operação cara), aplicamos o logaritmo de base 2 em ambos os lados:
$$\log_2(y) = \log_2(x^{-1/2})$$
$$\log_2(y) = -\frac{1}{2} \log_2(x)$$

---

### Etapa 2: A Representação de Ponto Flutuante (IEEE 754)
Um número $x$ no computador é representado por um bit de sinal (que ignoramos aqui), um expoente $E$ e uma mantissa $M$. A fórmula do valor é:
$$x = 2^{E-B} \cdot (1 + M)$$
*Onde $B$ é o bias (127) e $0 \le M < 1$.*

Aplicando o logaritmo nesta estrutura:
$$\log_2(x) = \log_2(2^{E-B} \cdot (1 + M)) = (E-B) + \log_2(1 + M)$$

---

### Etapa 3: A Aproximação Linear
Aqui entra o "pulo do gato". Para $0 \le M < 1$, a função $\log_2(1+M)$ é quase uma reta. Podemos aproximá-la por:
$$\log_2(1 + M) \approx M + \sigma$$
*Onde $\sigma$ é uma constante de ajuste (em Quake, cerca de $0.0450465$).*

Logo:
$$\log_2(x) \approx E - B + M + \sigma$$

---

### Etapa 4: Relacionando com os Bits Inteiros
Se olharmos para os bits do float como se fossem um número inteiro $L$, a estrutura de 32 bits coloca o expoente nos bits altos e a mantissa nos baixos:
$$L = 2^{23} \cdot E + (2^{23} \cdot M)$$
$$L = 2^{23} \cdot (E + M)$$

Se isolarmos $E+M$ e substituirmos na nossa aproximação do logaritmo (Etapa 3):
$$\log_2(x) \approx \frac{L}{2^{23}} - B + \sigma$$

---

### Etapa 5: Determinando o Algoritmo
Agora substituímos essa relação de bits na nossa equação original da Etapa 1 ($\log_2(y) = -\frac{1}{2} \log_2(x)$):

$$\frac{L_y}{2^{23}} - B + \sigma \approx -\frac{1}{2} \left( \frac{L_x}{2^{23}} - B + \sigma \right)$$

Multiplicando tudo por $2^{23}$ e isolando $L_y$ (os bits do resultado):
$$L_y \approx \frac{3}{2} 2^{23} (B - \sigma) - \frac{1}{2} L_x$$

### Conclusão: A Forma Final do Código
O termo $\frac{3}{2} 2^{23} (B - \sigma)$ é uma constante pura. Se você plugar $B=127$ e o $\sigma$ escolhido, o resultado é o **Número Mágico** $K$.

A operação final em código torna-se:
1.  `i = K - (i >> 1);` (Onde `>> 1` é a divisão de $L_x$ por 2).
2.  `y = f(y);` (Uma iteração de Newton para corrigir o erro da aproximação linear da Etapa 3).

Como você gosta de C++, note que o Newton aqui é:
$$y_{n+1} = y_n \left( \frac{3}{2} - \frac{x}{2} y_n^2 \right)$$
Que é exatamente o `y * (1.5f - xhalf * y * y)` do código.


A ideia de usar o *type punning* via ponteiro (o famoso “evil bit hack”) até funciona em muitos compiladores, mas **não é seguro segundo o padrão C** (viola *strict aliasing*). Para algo robusto — especialmente no seu nível — vale mostrar **as duas abordagens**:

---

# ✅ Versão 1 (CORRETA e PORTÁVEL) — usando `memcpy`

```c
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_bits(uint32_t x) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i == 31 || i == 23) printf(" "); // separa S | E | M
    }
    printf("\n");
}

int main() {
    float y = -6.625f;

    uint32_t bits;
    memcpy(&bits, &y, sizeof(bits)); // forma segura

    // Extrair campos
    uint32_t sign     = (bits >> 31) & 0x1;
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
```

---

# ⚠️ Versão 2 (EVIL BIT HACK) — estilo que você sugeriu

Funciona na prática, mas **teoricamente UB (Undefined Behavior)**:

```c
#include <stdio.h>

int main() {
    float y = -6.625f;

    // Etapa 1: Evil Bit Hack
    long i = *(long*)&y;

    unsigned int sign     = (i >> 31) & 0x1;
    unsigned int exponent = (i >> 23) & 0xFF;
    unsigned int mantissa = i & 0x7FFFFF;

    printf("Valor: %f\n\n", y);

    printf("Raw bits (hex): 0x%lX\n\n", i);

    printf("Sinal     = %u\n", sign);
    printf("Expoente  = %u\n", exponent);
    printf("Mantissa  = 0x%06X\n", mantissa);

    printf("\nExpoente real = %d\n", (int)exponent - 127);

    return 0;
}
```

---

# 🔍 O que você vai observar ao rodar

Para `-6.625`, a saída será algo como:

```
Sinal     = 1
Expoente  = 129
Mantissa  = 0x540000
Expoente real = 2
```

E os bits:

```
1 10000001 10101000000000000000000
```

---

# 💡 Observação importante (nível avançado)

* O hack:

  ```c
  *(long*)&y
  ```

  depende de:

  * tamanho de `long` (pode ser 64 bits!)
  * alinhamento
  * regras de aliasing

👉 Forma moderna recomendada:

* `memcpy`
* ou `union` (mais idiomático em C)

---

# 🧠 Se quiser ir além

Posso te mostrar:

* como reconstruir o número manualmente em C (tipo seu passo a passo)
* como detectar **NaN, infinito, subnormal**
* ou como fazer isso com **double (64 bits)**

Só dizer 👍


Aqui tem um equívoco conceitual importante: **deslocar os bits (`>> 1`) NÃO equivale a dividir um `float` por 2**.

Você está misturando duas representações diferentes:

* `bits` → inteiro (`uint32_t`)
* `y` → número em ponto flutuante

---

## ⚠️ Problema do seu código

```c
bits = (bits >> 1);
print_bits(bits);
printf("%f\n", bits); // ❌ errado
```

### Por quê?

1. `bits >> 1`:

   * desloca TODOS os bits (incluindo sinal e expoente)
   * destrói completamente a estrutura IEEE 754

2. `printf("%f", bits)`:

   * `%f` espera `double`
   * você está passando `uint32_t`
     👉 comportamento indefinido

---

## ✅ Como dividir corretamente por 2 (nível IEEE 754)

Dividir por 2 em float é equivalente a:

[
E_{novo} = E - 1
]

Ou seja: **diminuir o expoente em 1** (quando não é caso especial).

---

## ✔️ Código correto manipulando o expoente

```c
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_bits(uint32_t x) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i == 31 || i == 23) printf(" ");
    }
    printf("\n");
}

int main() {
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
```

---

## 🧠 Resultado esperado

```
Original:  -6.625
Resultado: -3.3125
```

Porque:

[
-6.625 / 2 = -3.3125
]

---

## 🔬 Comparação importante

| Método           | Resultado | Correto? |
| ---------------- | --------- | -------- |
| `bits >> 1`      | lixo      | ❌        |
| `y / 2.0f`       | -3.3125   | ✅        |
| ajustar expoente | -3.3125   | ✅        |

---

## 💡 Insight avançado (bem importante)

O IEEE 754 é estruturado assim:

[
(-1)^S \cdot 1.M \cdot 2^{E-127}
]

👉 Dividir por 2 = diminuir potência de 2
👉 Ou seja = **mexer no expoente, não nos bits crus**

---

## Se quiser evoluir mais

Posso te mostrar:

* como implementar `float_half()` igual ao problema clássico do CS:APP
* como lidar com **subnormal**
* ou fazer isso sem usar `float`, só com bits (hardcore 😄)

Só falar 👍



Direto ao ponto: **para dividir por 2 em IEEE 754 normalizado, você altera o EXPOENTE — não a mantissa.**

---

## 🎯 Regra fundamental

Um float é:

[
(-1)^S \cdot 1.M \cdot 2^{E-127}
]

👉 Dividir por 2 ⇒ reduzir a potência de 2:

[
2^{E-127} \rightarrow 2^{(E-1)-127}
]

✔️ Portanto:

```c
E = E - 1;
```

---

## 🧠 Então a resposta é:

👉 **Você mexe no EXPOENTE (campo E)**
👉 **Não mexe na mantissa (M)**

---

## 📌 Seu código está correto até aqui

```c
uint32_t exponent = (bits >> 23) & 0xFF;
```

Agora o passo certo:

```c
exponent -= 1;
```

---

## 🔬 Exemplo com seu número (-6.625)

Antes:

```text
1 10000001 101010...
  ^ expoente = 129
```

Depois de dividir por 2:

```text
1 10000000 101010...
  ^ expoente = 128
```

---

## ⚠️ Quando a mantissa entra na história?

Boa pergunta — aqui começa o nível avançado:

### 👉 Você mexe na mantissa SOMENTE se:

### 1. Número subnormal (E = 0)

* Não existe mais o `1.` implícito
* Aí sim:

```c
mantissa >>= 1;
```

---

### 2. Underflow (quando E iria ficar < 1)

Exemplo:

```text
E = 1  → dividir por 2 → vira subnormal
```

Nesse caso:

* expoente vira 0
* mantissa precisa ser ajustada

---

## 📊 Resumo claro

| Caso              | O que alterar     |
| ----------------- | ----------------- |
| Normal (E > 1)    | **expoente--**    |
| E = 1 (limite)    | vira subnormal    |
| Subnormal (E = 0) | **mantissa >> 1** |

---

## 💡 Intuição forte

* **Expoente controla escala (potência de 2)**
* **Mantissa controla precisão (forma do número)**

👉 Dividir por 2 = mudar escala → **expoente**

---

## Se quiser aprofundar (vale muito)

Posso te mostrar:

* implementação completa de `float_half()` (tipo CS:APP)
* tratamento de:

  * NaN
  * infinito
  * subnormal
* fazer isso só com bits (sem usar float)

Só dizer 👍


Vamos converter **222.658** para **IEEE 754 float 32 bits**.

## 1. Sinal

Como o número é positivo:

```text
S = 0
```

---

## 2. Parte inteira em binário

```text
222 / 2 = 111 resto 0
111 / 2 = 55  resto 1
55  / 2 = 27  resto 1
27  / 2 = 13  resto 1
13  / 2 = 6   resto 1
6   / 2 = 3   resto 0
3   / 2 = 1   resto 1
1   / 2 = 0   resto 1
```

Lendo de baixo para cima:

```text
222 = 11011110₂
```

---

## 3. Parte fracionária em binário

Parte fracionária:

```text
0.658
```

Multiplicando por 2:

```text
0.658 × 2 = 1.316  → 1
0.316 × 2 = 0.632  → 0
0.632 × 2 = 1.264  → 1
0.264 × 2 = 0.528  → 0
0.528 × 2 = 1.056  → 1
0.056 × 2 = 0.112  → 0
0.112 × 2 = 0.224  → 0
0.224 × 2 = 0.448  → 0
0.448 × 2 = 0.896  → 0
0.896 × 2 = 1.792  → 1
...
```

Então:

```text
0.658 ≈ 0.101010000111001010110000...₂
```

Logo:

```text
222.658 ≈ 11011110.101010000111001010110000...₂
```

---

## 4. Normalização

Deslocamos a vírgula até ficar na forma:

```text
1.xxxxx × 2ⁿ
```

Temos:

```text
11011110.101010000111001010110000...
```

Movendo a vírgula 7 casas para a esquerda:

```text
1.101111010101000011100101011000... × 2⁷
```

Portanto:

```text
expoente real = 7
```

---

## 5. Expoente com bias 127

```text
E = 7 + 127 = 134
```

Agora converter 134 para binário:

```text
134 = 10000110₂
```

Então:

```text
Expoente = 10000110
```

---

## 6. Mantissa

Da forma normalizada:

```text
1.101111010101000011100101011000...
```

O `1.` inicial é implícito. Guardamos apenas os bits depois da vírgula:

```text
101111010101000011100101011000...
```

A mantissa tem 23 bits:

```text
10111101010100001110010
```

Mas o próximo bit é `1`, então ocorre arredondamento:

```text
10111101010100001110010
+                      1
-----------------------
10111101010100001110011
```

Mantissa final:

```text
10111101010100001110011
```

---

## 7. Representação IEEE 754 final

```text
Sinal     = 0
Expoente  = 10000110
Mantissa  = 10111101010100001110011
```

Juntando:

```text
0 10000110 10111101010100001110011
```

Em 32 bits:

```text
01000011010111101010100001110011
```

Agrupando em hexadecimal:

```text
0100 0011 0101 1110 1010 1000 0111 0011
 4    3    5    E    A    8    7    3
```

Resultado:

```text
0x435EA873
```

---

# Forma algébrica

O formato IEEE 754 simples é:

[
x = (-1)^S \cdot (1 + M) \cdot 2^{E - 127}
]

Para o nosso caso:

```text
S = 0
E = 134
E - 127 = 7
```

A mantissa é:

```text
10111101010100001110011
```

Logo:

[
M =
1\cdot2^{-1}
+0\cdot2^{-2}
+1\cdot2^{-3}
+1\cdot2^{-4}
+1\cdot2^{-5}
+1\cdot2^{-6}
+0\cdot2^{-7}
+\cdots
]

Então o número armazenado é:

[
x = (-1)^0 \cdot 1.10111101010100001110011_2 \cdot 2^7
]

Ou seja:

```text
1.10111101010100001110011₂ × 2⁷
```

Desnormalizando:

```text
11011110.1010100001110011₂
```

Esse valor não volta exatamente para `222.658`, porque `0.658` não tem representação binária finita.

O valor real armazenado no float é aproximadamente:

```text
222.6580047607421875
```

Então:

```text
222.658 ≈ 0x435EA873
```


