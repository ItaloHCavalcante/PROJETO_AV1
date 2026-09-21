## Pseudocódigo

```text
L1    função (A[n][n]):
L2        contador = 0;
L3        para i variando de 1 até n faça:
L4            para j variando de i até n faça:
L5                soma = A[i][j] + A[j][i];
L6                resto = soma mod 5; // calcula o resto da divisão por 5
L7                se resto = 0 então
L8                    contador = contador + 1;
L9        retorne contador;
```

## Complexidade — frequência de execução no pior caso

| Linha | Quantidade de execuções |
|---|---|
| L1 | 0 — declaração da função |
| L2 | 1 |
| L3 | n + 1 |
| L4 | (n² + 3n) / 2 |
| L5 | (n² + n) / 2 |
| L6 | (n² + n) / 2 |
| L7 | (n² + n) / 2 |
| L8 | (n² + n) / 2 |
| L9 | 1 |

No pior caso, todas as somas são múltiplas de 5, fazendo a L8 executar em todas as iterações.

A contagem considera uma unidade por execução de linha e inclui as verificações finais dos laços.

## Fórmula

T(n) = (5n² + 9n + 6) / 2

## Big O

O(n²) — complexidade quadrática.

## Tempo estimado — método simplificado do slide

Considerando:

- n = 500;
- 10⁸ instruções por segundo;
- n² como estimativa simplificada da quantidade de instruções.

Cálculo:

```text
500² = 250.000 = 2,5 × 10⁵

x = (2,5 × 10⁵) / 10⁸
x = 2,5 × 10⁻³ s
x = 0,0025 s
```

**Tempo estimado: 0,0025 segundo, equivalente a 2,5 milissegundos.**